#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>

using namespace std;

	/**
	 * @class Date
	 * @brief  Manages the day, month and year with overloaded operator for comparisons
	 *
	 * This class will handle the day in numbers, months in alphabets and years in numbers.
	 *
	 * @author Wei Xing
	 * @version 02
	 * @date 20/07/2022 Wei Xing, Modified
	 *
	 * @todo None for now
	 *
	 * @bug To the best of my knowledge, my program has no bugs
	 */

class Date
{
public:
    Date();
    Date(const int day, const int month, const int year);

        /**
         * Set day
         * @param day
         * @return None
         */
    void SetDay(const int day);

        /**
         * Set month
         * @param month
         * @return None
         */
    void SetMonth(const int month);

        /**
         * Set year
         * @param year
         * @return None
         */
    void SetYear(const int year);

        /**
         * Return day
         * @param None
         * @return Day
         */
    int GetDay() const;

        /**
         * Return month
         * @param None
         * @return Month
         */
    int GetMonth() const;

        /**
         * Return year
         * @param None
         * @return Year
         */
    int GetYear() const;

        /**
         * Overloaded operator for less than comparison
         * @param Date object
         * @return true/false
         */
    bool operator < (const Date& d) const;

        /**
         * Overloaded operator for more than comparison
         * @param Date object
         * @return true/false
         */
    bool operator > (const Date& d) const;

        /**
         * Overloaded operator for equal comparison
         * @param Date object
         * @return true/false
         */
    bool operator == (const Date& d) const;

private:
        /// Day in numbers
    int m_day;

        /// Month in alphabets
    int m_month;

        /// Year in numbers
    int m_year;

};

ostream & operator <<( ostream & os, const Date & D );
istream & operator >>( istream & input, Date & D );

#endif
