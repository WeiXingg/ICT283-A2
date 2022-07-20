#include "Date.h"
#include <string>

Date::Date() // Default constructor
{
    m_day = 0;
    m_month = 0;
    m_year = 0;
}

Date::Date(const int day, const int month, const int year) // Parameterized constructor
{
    m_day = day;
    m_month = month;
    m_year = year;
}

void Date::SetDay(const int day) // Setter for day
{
    m_day = day;
}

void Date::SetMonth(const int month) // Setter for month
{
    m_month = month;
}
void Date::SetYear(const int year) // // Setter for year
{
    m_year = year;
}

int Date::GetDay() const // Getter for day
{
    return m_day;
}

int Date::GetMonth() const // Getter for month
{
    return m_month;
}

int Date::GetYear() const // Getter for year
{
    return m_year;
}

bool Date::operator < (const Date& d) const // Overloaded operator for less than comparison
{
    if (m_year < d.m_year) return true;
    if (m_year == d.m_year && m_month < d.m_month) return true;
    if ((m_year == d.m_year && m_month == d.m_month) && m_day < d.m_day) return true;
    return false;
}

bool Date::operator > (const Date& d) const // Overloaded operator for more than comparison
{
    if (m_year > d.m_year) return true;
    if (m_year == d.m_year && m_month > d.m_month) return true;
    if ((m_year == d.m_year && m_month == d.m_month) && m_day > d.m_day) return true;
    return false;
}

bool Date::operator == (const Date& d) const // Overloaded operator for equal comparison
{
    if (m_year == d.m_year && m_month == d.m_month && m_day == d.m_day) return true;
    return false;
}

istream & operator >>( istream & input, Date & D )
{
    string day, month, year;
    getline(input, day, '/');
    D.SetDay(stoi(day));
    getline(input, month, '/');
    D.SetMonth(stoi(month));
    getline(input, year, ' ');
    D.SetYear(stoi(year));
    return input;
}

ostream & operator <<( ostream & os, const Date & D )
{
    os  << D.GetDay() << "/" << D.GetMonth()
        << "/" << D.GetYear();
    return os;
}
