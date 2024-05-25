#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#include "array_helpers.h"

int temp_min (WeatherTable a){
    int min = INT_MAX;
    for (unsigned int year = 0u; year < YEARS; ++year){
        for (month_t month = january; month <= december; ++month){
            for (unsigned int day = 0u; day < DAYS; ++day){
                if(min > a[year][month][day]._min_temp){
                    min = a[year][month][day]._min_temp;
                }
            }
        }
    }
    return min;
}

void temp_max_of_the_year (WeatherTable a, int output[YEARS]){
    int max = INT_MIN;
    for (unsigned int year = 0u; year < YEARS; ++year){
        for (month_t month = january; month <= december; ++month){
            for (unsigned int day = 0u; day < DAYS; ++day){
                if(max < a[year][month][day]._max_temp){
                    max = a[year][month][day]._max_temp;
                }
            }
        }
        output[year] = max;
    }
}

void max_rain_of_the_month_of_the_year (WeatherTable a, unsigned int rain_max[YEARS]){
    for (unsigned int year = 0u; year < YEARS; ++year){
        unsigned int max_rain_of_the_month = 0;
        for (month_t month = january; month <= december; ++month){
            unsigned int rain_of_the_day = 0;
            for (unsigned int day = 0u; day < DAYS; ++day){
                rain_of_the_day = rain_of_the_day + a[year][month][day]._rainfall;
            }
            if (max_rain_of_the_month < rain_of_the_day){
                max_rain_of_the_month = rain_of_the_day;
                rain_max[year] = month;
            }
        }
    }
}

