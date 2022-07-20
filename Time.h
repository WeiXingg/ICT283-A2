#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <iostream>

using namespace std;

	/**
	 * @class Time
	 * @brief  Manages the hour and minute with overloaded operator for comparisons
	 *
	 * This class will only handle hours and minutes and not seconds or milliseconds.
	 *
	 * @author Wei Xing
	 * @version 02
	 * @date 20/07/2022 Wei Xing, Modified
	 *
	 * @todo None for now
	 *
	 * @bug To the best of my knowledge, my program has no bugs
	 */

class Time
{
public:
    Time();
    Time(const unsigned hour, const unsigned minute);

        /**
         * Set hour
         * @param hour
         * @return None
         */
    void SetHour(const unsigned hour);

        /**
         * Set minute
         * @param minute
         * @return None
         */
    void SetMinute(const unsigned minute);

        /**
         * Get hour
         * @param None
         * @return Hour
         */
    unsigned GetHour() const;

        /**
         * Get minute
         * @param None
         * @return Minute
         */
    unsigned GetMinute() const;

        /**
         * Overloaded operator for less than comparison
         * @param Time object
         * @return true/false
         */
    bool operator < (const Time& t) const;

        /**
         * Overloaded operator for more than comparison
         * @param Time object
         * @return true/false
         */
    bool operator > (const Time& t) const;

        /**
         * Overloaded operator for equal comparison
         * @param Time object
         * @return true/false
         */
    bool operator == (const Time& t) const;

private:
        /// Hour in numbers
    unsigned m_hour;

        /// Minute in numbers
    unsigned m_minute;
};

ostream & operator <<( ostream & os, const Time & T );
istream & operator >>( istream & input, Time & T );

#endif
