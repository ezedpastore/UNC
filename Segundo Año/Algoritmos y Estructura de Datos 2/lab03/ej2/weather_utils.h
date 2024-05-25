#ifndef WEATHER_UTILS_H
#define WEATHER_UTILS_H

#include "array_helpers.h"

int temp_min (WeatherTable a);

void temp_max_of_the_year (WeatherTable a, int output[YEARS]);

void max_rain_of_the_month_of_the_year (WeatherTable a, unsigned int rain_max[YEARS]);

#endif
