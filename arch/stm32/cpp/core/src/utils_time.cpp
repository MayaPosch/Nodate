/*
	utils_time.cpp - Implemented file for Nodate time-related functions.
*/


#include <utils_time.h>

#include <cstdint>


/* Time constants. */
#define SECONDS_BY_MINUTES 60
#define MINUTES_BY_HOUR 60
#define SECONDS_BY_HOUR (SECONDS_BY_MINUTES * MINUTES_BY_HOUR)
#define HOURS_BY_DAY 24
#define SECONDS_BY_DAY (SECONDS_BY_HOUR * HOURS_BY_DAY)
#define LAST_VALID_YEAR 206


/* Macros which will be used to determine if we are within valid range. */
#define EDGE_TIMESTAMP_FULL_LEAP_YEAR_SUPPORT 3220095     // 7th of February 1970 at 06:28:15
#define EDGE_TIMESTAMP_4_YEAR_LEAP_YEAR_SUPPORT 3133695  // 6th of February 1970 at 06:28:15

/*
 * 2 dimensional array containing the number of seconds elapsed before a given
 * month.
 * The second index map to the month while the first map to the type of year:
 *   - 0: non leap year
 *   - 1: leap year
 */
static const uint32_t seconds_before_month[2][12] = {
    {
        0,
        31 * SECONDS_BY_DAY,
        (31 + 28) *SECONDS_BY_DAY,
        (31 + 28 + 31) *SECONDS_BY_DAY,
        (31 + 28 + 31 + 30) *SECONDS_BY_DAY,
        (31 + 28 + 31 + 30 + 31) *SECONDS_BY_DAY,
        (31 + 28 + 31 + 30 + 31 + 30) *SECONDS_BY_DAY,
        (31 + 28 + 31 + 30 + 31 + 30 + 31) *SECONDS_BY_DAY,
        (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31) *SECONDS_BY_DAY,
        (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30) *SECONDS_BY_DAY,
        (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31) *SECONDS_BY_DAY,
        (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30) *SECONDS_BY_DAY,
    },
    {
        0,
        31 * SECONDS_BY_DAY,
        (31 + 29) *SECONDS_BY_DAY,
        (31 + 29 + 31) *SECONDS_BY_DAY,
        (31 + 29 + 31 + 30) *SECONDS_BY_DAY,
        (31 + 29 + 31 + 30 + 31) *SECONDS_BY_DAY,
        (31 + 29 + 31 + 30 + 31 + 30) *SECONDS_BY_DAY,
        (31 + 29 + 31 + 30 + 31 + 30 + 31) *SECONDS_BY_DAY,
        (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31) *SECONDS_BY_DAY,
        (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30) *SECONDS_BY_DAY,
        (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31) *SECONDS_BY_DAY,
        (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30) *SECONDS_BY_DAY,
    }
};


bool _rtc_is_leap_year(int year, rtc_leap_year_support_t leap_year_support) {
    /*
     * since in practice, the value manipulated by this algorithm lie in the
     * range: [70 : 206] the algorithm can be reduced to: year % 4 with exception for 200 (year 2100 is not leap year).
     * The algorithm valid over the full range of value is:

        year = 1900 + year;
        if (year % 4) {
            return false;
        } else if (year % 100) {
            return true;
        } else if (year % 400) {
            return false;
        }
        return true;

     */
    if (leap_year_support == RTC_FULL_LEAP_YEAR_SUPPORT && year == 200) {
        return false; // 2100 is not a leap year
    }

    return (year) % 4 ? false : true;
}



bool _rtc_maketime(const struct tm *time, time_t *seconds, 
					rtc_leap_year_support_t leap_year_support) {
    if (seconds == NULL || time == NULL) {
        return false;
    }

    /* Partial check for the upper bound of the range - check years only. Full check will be performed after the
     * elapsed time since the beginning of the year is calculated.
     */
    if ((time->tm_year < 70) || (time->tm_year > LAST_VALID_YEAR)) {
        return false;
    }

    uint32_t result = time->tm_sec;
    result += time->tm_min * SECONDS_BY_MINUTES;
    result += time->tm_hour * SECONDS_BY_HOUR;
    result += (time->tm_mday - 1) * SECONDS_BY_DAY;
    result += seconds_before_month[_rtc_is_leap_year(time->tm_year, leap_year_support)][time->tm_mon];

    /* Check if we are within valid range. */
    if (time->tm_year == LAST_VALID_YEAR) {
        if ((leap_year_support == RTC_FULL_LEAP_YEAR_SUPPORT && 
				result > EDGE_TIMESTAMP_FULL_LEAP_YEAR_SUPPORT) || 
				(leap_year_support == RTC_4_YEAR_LEAP_YEAR_SUPPORT && 
				result > EDGE_TIMESTAMP_4_YEAR_LEAP_YEAR_SUPPORT)) {
            return false;
        }
    }

    if (time->tm_year > 70) {
        /* Valid in the range [70:206]. */
        uint32_t count_of_leap_days = ((time->tm_year - 1) / 4) - (70 / 4);
        if (leap_year_support == RTC_FULL_LEAP_YEAR_SUPPORT) {
            if (time->tm_year > 200) {
                count_of_leap_days--; // 2100 is not a leap year
            }
        }

        result += (((time->tm_year - 70) * 365) + count_of_leap_days) * SECONDS_BY_DAY;
    }

    *seconds = result;

    return true;
}
