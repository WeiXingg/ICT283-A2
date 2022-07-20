#ifndef WINDLOG_H_INCLUDED
#define WINDLOG_H_INCLUDED

#include "Date.h"
#include "Time.h"
#include <iostream>

using namespace std;

	/**
	 * @class Windlog
	 * @brief  Manages date and time object and additional variables needed
	 *
	 * A Windlog class created specifically to handle date and time objects with additional variable of
	 * wind speed, solar radiation and air temperature.
	 *
	 * @author Wei Xing
	 * @version 01
	 * @date 21/07/2022 Wei Xing, Modified
	 *
	 * @todo None for now
	 *
	 * @bug To the best of my knowledge, my program has no bugs
	 */

class Windlog
{
public:
    Windlog();
    Windlog(const Date& date, const Time& time, const float windSpeed,
            const float solarRadiation, const float airTemperature);

        /**
         * Set date object
         * @param Date object
         * @return None
         */
    void SetDate(const Date& date);

        /**
         * Set time object
         * @param Time object
         * @return None
         */
    void SetTime(const Time& time);

        /**
         * Set wind speed
         * @param Wind speed
         * @return None
         */
    void SetWindSpeed(const float windSpeed);

        /**
         * Set solar radiation
         * @param Solar radiation
         * @return None
         */
    void SetSolarRadiation(const float solarRadiation);

        /**
         * Set airTemperature
         * @param Air temperature
         * @return None
         */
    void SetAirTemperature(const float airTemperature);

        /**
         * Get date object
         * @param Date object
         * @return None
         */
    void GetDate(Date& date) const;

        /**
         * Get time object
         * @param Time object
         * @return None
         */
    void GetTime(Time& time) const;

        /**
         * Get wind speed
         * @param None
         * @return Wind speed
         */
    float GetWindSpeed() const;

        /**
         * Get solar radiation
         * @param None
         * @return Solar radiation
         */
    float GetSolarRadiation() const;

        /**
         * Get air temperature
         * @param None
         * @return Air temperature
         */
    float GetAirTemperature() const;

private:
        /// Date object
    Date m_date;

        /// Time object
    Time m_time;

        /// Wind Speed
    float m_windSpeed;

        /// Solar Radiation
    float m_solarRadiation;

        /// Air Temperature
    float m_airTemperature;
};

ostream & operator <<( ostream & os, const Windlog & wl );
istream & operator >>( istream & input, Windlog & wl );

#endif
