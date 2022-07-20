#include "Windlog.h"
#include <string>

Windlog::Windlog() // Default constructor
{
    m_windSpeed = 0;
    m_solarRadiation = 0;
    m_airTemperature = 0;
}

Windlog::Windlog(const Date& date, const Time& time, const float windSpeed,
                 const float solarRadiation,const float airTemperature) // Parameterized constructor
{
    m_date = date;
    m_time = time;
    m_windSpeed = windSpeed;
    m_solarRadiation = solarRadiation;
    m_airTemperature = airTemperature;
}

void Windlog::SetDate(const Date& date) // Setter for date object
{
    m_date = date;
}

void Windlog::SetTime(const Time& time) // Setter for time object
{
    m_time = time;
}

void Windlog::SetWindSpeed(const float windSpeed) // Setter for wind speed
{
    m_windSpeed = windSpeed;
}

void Windlog::SetSolarRadiation(const float solarRadiation) // Setter for solar radiation
{
    m_solarRadiation = solarRadiation;
}

void Windlog::SetAirTemperature(const float airTemperature) // Setter air temperature
{
    m_airTemperature = airTemperature;
}

void Windlog::GetDate(Date& date) const // Getter for date object
{
    date = m_date;
}

void Windlog::GetTime(Time& time) const // Getter for time object
{
    time = m_time;
}

float Windlog::GetWindSpeed() const // Getter for wind speed
{
    return m_windSpeed;
}

float Windlog::GetSolarRadiation() const // Getter for wind speed
{
    return m_solarRadiation;
}

float Windlog::GetAirTemperature() const // Getter for air temperature
{
    return m_airTemperature;
}

istream & operator >>( istream & input, Windlog & wl )
{
    Date tempDate;
    Time tempTime;
    string skipLine, tempWindSpeed, tempSolarRadiation, tempAirTemperature;
    input >> tempDate >> tempTime;
    wl.SetDate(tempDate);
    wl.SetTime(tempTime);
    for (int i = 0; i < 9; i++) // Skip through 9 data with , as delimiter
    {
        getline(input, skipLine, ',');
    }
    getline(input, tempWindSpeed, ',');
    wl.SetWindSpeed(stof(tempWindSpeed));
    getline(input, tempSolarRadiation, ',');
    wl.SetSolarRadiation(stof(tempSolarRadiation));
    for (int i = 0; i < 5; i++) // Skip through 5 data with , as delimiter
    {
        getline(input, skipLine, ',');
    }
    getline(input, tempAirTemperature, ',');
    wl.SetAirTemperature(stof(tempAirTemperature));
    return input;
}

ostream & operator <<( ostream & os, const Windlog & wl )
{
    Date tempDate;
    Time tempTime;
    wl.GetDate(tempDate);
    wl.GetTime(tempTime);
    os  << tempDate << "," << tempTime << ","
        << wl.GetWindSpeed() << "," << wl.GetSolarRadiation()
        << "," << wl.GetAirTemperature();
    return os;
}
