#include "Date.h"
#include "Time.h"
#include "Windlog.h"
#include "BinarySearchTree.h"
#include <map>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>

// Forward declarations
typedef map<int, map<int, map<string, BinarySearchTree<float>>>> mapAndBst;
typedef map<int, map<int, map<int, map<float, BinarySearchTree<Time>>>>> mapSolarRadTime;
void Menu(mapAndBst& windLog, mapSolarRadTime& solarTime);
bool LoadFile(mapAndBst& data, mapSolarRadTime& solarTime);
int CheckYearInput();
int CheckMonthInput();
int CheckDayInput();
const string CheckMonth(const int month);
float CalculateAvgSpeed(BinarySearchTree<float>& data);
float CalculateAvgTemperature(BinarySearchTree<float>& data);
float CalculateTotalSolarRadiation(BinarySearchTree<float>& data);
void OptionOne(mapAndBst& windLog);
void OptionTwo(mapAndBst& windLog);
void OptionThree(mapAndBst& windLog);
void OptionFour(mapAndBst& windLog);
void OptionFive(mapSolarRadTime& solarTime);
void Print(float& x);
void Print(Time& x);
void GetSumAndCount(float& data, float& totalSum, unsigned& count, unsigned& totalCount);
void GetSumAndCountSolarRad(float& data, float& totalSum, unsigned& count, unsigned& totalCount);

int main()
{
    mapAndBst windLog;
    mapSolarRadTime solarRadTime;
    if (LoadFile(windLog, solarRadTime)) //To check if file is successfully loaded
    {
        Menu(windLog, solarRadTime);
    }
    return 0;
}

void Menu(mapAndBst& windLog, mapSolarRadTime& solarRadTime)
{
    int input;
    bool flag = true;
    while(flag) // To keep the program running until user selects exit
    {
        cout << "The program will keep running until you choose to exit.\n" << endl
             << "Choose from option 1 to 5." << endl
             << "1. View the average wind speed and ambient air temperature for a specified month and year." << endl
             << "2. View average wind speed and ambient air temperature for each month of a specified year." << endl
             << "3. View total solar radiation in kWh/m2 for each month of a specified year." << endl
             << "4. Write to a file for the average wind speed in km/h, average ambient air temperature and total solar "
             "radiation in \n   kWh/m2 for each month of a specified year." << endl
             << "5. Show the times for the highest solar radiation for your specified date." << endl
             << "6. Exit the program." << endl;
        cout << "\nYour option: " << endl;
        cin >> input;
        while (input < 1 || input > 6) // Validation of user input
        {
            cout << "\nEnter a valid response:" << endl;
            cin.clear();
            cin.ignore(123, '\n');
            cin >> input;
        }
        switch (input) // Switch case for user input
        {
        case 1:
            OptionOne(windLog);
            break;

        case 2:
            OptionTwo(windLog);
            break;

        case 3:
            OptionThree(windLog);
            break;

        case 4:
            OptionFour(windLog);
            break;

        case 5:
            OptionFive(solarRadTime);
            break;

        case 6:
            cout << "\nThe program will end." << endl;
            flag = false;
            break;

        default:
            break;
        }
    }
}

bool LoadFile(mapAndBst& data, mapSolarRadTime& solarRadTime)
{
    Windlog tempWindlog;
    Date tempDate;
    Time tempTime;
    string tempString, oneLine;
    int counter = 0;
    ifstream input("data/met_index.txt");
    if (!input)
    {
        cout << "File not found. Please ensure file name is correct and run program again." << endl;
        return false;
    }
    else
    {
        while (getline(input, oneLine,'\n'))
        {
            ifstream infile("data/"+oneLine);
            getline(infile, tempString, '\n'); // Skip first line in input file
            while (getline(infile, tempString, '\n')) // Loop through every line in file
            {
                if (tempString.empty()) // Check for empty line
                {
                    getline(infile, tempString, '\n'); // Skip empty line
                }
                else
                {
                    try
                    {
                        stringstream (tempString) >> tempWindlog; // Add data into object
                        tempWindlog.GetDate(tempDate);
                        tempWindlog.GetTime(tempTime);
                        // Line 133 to 136 are adding data into map and BST
                        data[tempDate.GetYear()][tempDate.GetMonth()]["WindSpeed"].Insert(tempWindlog.GetWindSpeed());
                        data[tempDate.GetYear()][tempDate.GetMonth()]["AirTemperature"].Insert(tempWindlog.GetAirTemperature());
                        data[tempDate.GetYear()][tempDate.GetMonth()]["SolarRadiation"].Insert(tempWindlog.GetSolarRadiation());
                        solarRadTime[tempDate.GetYear()][tempDate.GetMonth()][tempDate.GetDay()][tempWindlog.GetSolarRadiation()].Insert(tempTime);
                    }
                    catch(std::invalid_argument) // Error handling for invalid inputs
                    {
                        getline(infile, tempString, '\n');
                    }
                }
            }
            cout << "Loading of '" << oneLine << "' successful" << endl;
            counter++;
        }
        cout << "\nLoading of ( " << counter << " ) file successful, menu will be displayed below.\n" << endl;
        return true;
    }
}

int CheckYearInput() // Validation for year input by user
{
    int yearInput;
    cout << "\nEnter year: " << endl;
    cin >> yearInput;
    while (yearInput < 1000 || yearInput > 9999)
    {
        cout << "\nEnter a valid year:" << endl;
        cin.clear();
        cin.ignore(123, '\n');
        cin >> yearInput;
    }
    return yearInput;
}

int CheckMonthInput() // Validation for month input by user
{
    int monthInput;
    cout << "\nEnter month: " << endl;
    cout << "(Enter 1-12 e.g 1 for January)" << endl;
    cin >> monthInput;
    while (monthInput < 1 || monthInput > 12)
    {
        cout << "\nEnter a valid month:" << endl;
        cin.clear();
        cin.ignore(123, '\n');
        cin >> monthInput;
    }
    return monthInput;
}

int CheckDayInput() // Validation for day input by user
{
    int dayInput;
    cout << "\nEnter day: " << endl;
    cin >> dayInput;
    while (dayInput < 1 || dayInput > 31)
    {
        cout << "\nEnter a valid day:" << endl;
        cin.clear();
        cin.ignore(123, '\n');
        cin >> dayInput;
    }
    return dayInput;
}

const string CheckMonth(const int month)
{
    if(month <= 0 || month >= 13) // Ensure month is within range
        return "";
    string MONTH_STR[] = {"January", "February", "March", "April", "May", "June", "July", "August",
                          "September", "October", "November", "December"}; // String for list of months in alphabets
    return MONTH_STR[month - 1];
}

float CalculateAvgSpeed(BinarySearchTree<float>& data)
{
    unsigned totalCount = 0;
    float totalSum = 0;
    data.InOrderTraversalCalc(GetSumAndCount, totalSum, totalCount);
    return totalSum / totalCount * 3.6; // Average speed in km/h
}

float CalculateAvgTemperature(BinarySearchTree<float>& data)
{
    unsigned totalCount = 0;
    float totalSum = 0;
    data.InOrderTraversalCalc(GetSumAndCount, totalSum, totalCount);
    return totalSum / totalCount;
}

float CalculateTotalSolarRadiation(BinarySearchTree<float>& data)
{
    unsigned totalCount = 0;
    float totalSum = 0;
    data.InOrderTraversalCalc(GetSumAndCountSolarRad, totalSum, totalCount);
    return totalSum / 1000; // Total solar radiation in kWh/m2
}

void OptionOne(mapAndBst& windLog)
{
    int yearInput = CheckYearInput();
    int monthInput = CheckMonthInput();
    string outputMonth = CheckMonth(monthInput);
    if (windLog[yearInput][monthInput].size() == 0) // Check if there is data
    {
        cout << endl << outputMonth << " " << yearInput << ": No Data" << endl;
    }
    else
    {
        // Calculation for avg speed using WindSpeed as key and BST as value
        float avgSpeed = CalculateAvgSpeed(windLog[yearInput][monthInput]["WindSpeed"]);
        // Calculation for avg temp using AirTemperature as key and BST as value
        float avgTemperature = CalculateAvgTemperature(windLog[yearInput][monthInput]["AirTemperature"]);
        cout << '\n' << outputMonth << " " << yearInput << ": "
             << fixed << setprecision(1) << avgSpeed << " km/h, "
             << fixed << setprecision(1) << avgTemperature << " degrees C" << endl;
    }
    cout << endl;
}

void OptionTwo(mapAndBst& windLog)
{
    int yearInput = CheckYearInput();
    if (windLog[yearInput].size() == 0) // Check if there is data
    {
        cout << "\n" << yearInput << "\nNo Data" << endl;
    }
    else
    {
        cout << endl << yearInput << endl;
        for(int i = 1; i <= 12; i++)
        {
            string outputMonth = CheckMonth(i); // To retrieve month name from month string based on current index
            if (windLog[yearInput][i].size() == 0)  // Check if there is data
            {
                cout << outputMonth << ": No Data" << endl;
            }
            else
            {
                // Calculation for avg speed using WindSpeed as key and BST as value
                float avgSpeed = CalculateAvgSpeed(windLog[yearInput][i]["WindSpeed"]);
                // Calculation for avg temp using AirTemperature as key and BST as value
                float avgTemperature = CalculateAvgTemperature(windLog[yearInput][i]["AirTemperature"]);
                cout << outputMonth << ": "
                     << fixed << setprecision(1) << avgSpeed << " km/h, "
                     << fixed << setprecision(1) << avgTemperature << " degrees C" << endl;
            }
        }
    }
    cout << endl;
}

void OptionThree(mapAndBst& windLog)
{
    int yearInput = CheckYearInput();
    if (windLog[yearInput].size() == 0) // Check if there is data
    {
        cout << "\n" << yearInput << "\nNo Data" << endl;
    }
    else
    {
        cout << endl << yearInput << endl;
        for(int i = 1; i <= 12; i++)
        {
            string outputMonth = CheckMonth(i); // To retrieve month name from month string based on current index
            if (windLog[yearInput][i].size() == 0) // Check if there is data
            {
                cout << outputMonth << ": No Data" << endl;
            }
            else
            {
                // Calculation for total solar rad using SolarRadiation as key and BST as value
                float totalSolarRadiation = CalculateTotalSolarRadiation(windLog[yearInput][i]["SolarRadiation"]);
                cout << outputMonth << ": "
                     << fixed << setprecision(1) << totalSolarRadiation << " kWh/m2" << endl;
            }
        }
    }
    cout << endl;
}

void OptionFour(mapAndBst& windLog)
{
    ofstream ofile("WindTempSolar.csv");
    int yearInput = CheckYearInput();
    ofile << yearInput << endl;
    if (windLog[yearInput].size() == 0 ) // Check if there is data
    {
        ofile << "No data" << endl;
    }
    else
    {
        for(int i = 1; i <= 12; i++)
        {
            string outputMonth = CheckMonth(i); // To retrieve month name from month string based on current index
            if (windLog[yearInput][i].size() != 0) // Check if there is data
            {
                // Calculation for avg speed using WindSpeed as key and BST as value
                float avgSpeed = CalculateAvgSpeed(windLog[yearInput][i]["WindSpeed"]);
                // Calculation for avg temp using AirTemperature as key and BST as value
                float avgTemperature = CalculateAvgTemperature(windLog[yearInput][i]["AirTemperature"]);
                // Calculation for total solar rad using SolarRadiation as key and BST as value
                float totalSolarRadiation = CalculateTotalSolarRadiation(windLog[yearInput][i]["SolarRadiation"]);
                ofile << outputMonth << ","
                      << fixed << setprecision(1) << avgSpeed << ","
                      << fixed << setprecision(1) << avgTemperature << ","
                      << fixed << setprecision(1) << totalSolarRadiation << endl;
            }
        }
    }
    cout << "\nWindTempSolar.csv has been created\n" << endl;
}

void OptionFive(mapSolarRadTime& solarRadTime)
{
    int yearInput = CheckYearInput();
    int monthInput = CheckMonthInput();
    int dayInput = CheckDayInput();
    if(solarRadTime[yearInput][monthInput][dayInput].empty()) // Check if there is data
    {
        cout << "No data" << endl;
        return;
    }
    float largestSolar = solarRadTime[yearInput][monthInput][dayInput].rbegin()->first; // Retrieving largest value key in map
    cout << "\nDate: " << dayInput << "/" << monthInput << "/" << yearInput << endl
         << "High solar radiation for the day: " << largestSolar << " W/m2" << endl
         << "\nTime: " << endl;
    solarRadTime[yearInput][monthInput][dayInput][largestSolar].InOrderTraversal(Print); // Printing BST node(s) with largest value as key
    cout << endl;
}

void Print(float& x) // Pointer function for printing of BST nodes for float type
{
    cout << x << " ";
}

void Print(Time& x) // Pointer function for printing of BST nodes for Time object
{
    cout << x << endl;
}

void GetSumAndCount(float& data, float& totalSum, unsigned& count, unsigned& totalCount) // Pointer function to get total sum and total count
{
    totalSum += (data * count);
    totalCount += count;
}

void GetSumAndCountSolarRad(float& data, float& totalSum, unsigned& count, unsigned& totalCount) // Pointer function to get total sum and total count for solar radiation
{
    if (data >= 100)
    {
        totalSum += (data * count);
        totalCount += count;
    }
}
