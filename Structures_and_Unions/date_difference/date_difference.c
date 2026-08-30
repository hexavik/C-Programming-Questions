/**
 * @file date_difference.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-08-30
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Date {
    int day;
    int month;
    int year;
} Date;

// 
// Array of date count in each month of a year
// 
const int month_days[13] = { 0, 31, 28, 31, 30, 31,
    30, 31, 31, 30, 31, 30, 31 };

/**
 * @brief Check if the input year is a leap year or not
 * 
 * @param year Input year
 * @return int 0: false 1: true
 */
int is_leap_year(int year) {
    if (year % 400 == 0) { return 1; }
    if (year % 100 == 0) { return 0; }
    if (year % 4 == 0) { return 1; }
    return 0;
}

/**
 * @brief Count the total days of the input date
 * 
 * @param d Input Date struct
 * @return long int Total count of days
 */
long int count_total_days(Date d) {
    long int total_days = d.day;

    // Add days for the months in the current year
    for (int m = 1; m < d.month; ++m) {
        if (m == 2 && is_leap_year(d.year)) {
            total_days += 29;
        } else {
            total_days += month_days[m];
        }
    }

    // 
    // Add days for all preceding years, accounting for leap years
    //
    int y = d.year - 1;
    total_days += (long int)y * 365;
    total_days += (y / 4) - (y / 100) + (y / 400);

    return total_days;
}

/**
 * @brief Get the total days count from the first date to the second date
 * 
 * @param d1 Input first Date struct
 * @param d2 Input second Date struct
 * @return int Return the absolute difference
 */
int get_days_difference(Date d1, Date d2) {
    long int days1 = count_total_days(d1);
    long int days2 = count_total_days(d2);

    return (days2 > days1) ? days2 - days1 : days1 - days2;
}

int main() {
    Date date1 = { 15, 2, 2020 };
    Date date2 = { 20, 2, 2020 };

    printf("I/P: Date1: %02d/%02d/%02d, Date2: %02d/%02d/%02d\n",
        date1.day, date1.month, date1.year, date2.day, date2.month, date2.year);
    printf("O/P: Diff: %d days\n\n", get_days_difference(date1, date2));

    Date date3 = { 25, 2, 2020 };
    Date date4 = { 5, 3, 2020 };

    printf("I/P: Date3: %02d/%02d/%02d, Date4: %02d/%02d/%02d\n",
        date3.day, date3.month, date3.year, date4.day, date4.month, date4.year);
    printf("O/P: Diff: %d days\n\n", get_days_difference(date3, date4));

    Date date5 = { 2, 11, 2019 };
    Date date6 = { 22, 5, 2017 };

    printf("I/P: Date5: %02d/%02d/%02d, Date6: %02d/%02d/%02d\n",
        date5.day, date5.month, date5.year, date6.day, date6.month, date6.year);
    printf("O/P: Diff: %d days\n\n", get_days_difference(date5, date6));

    return 0;
}
