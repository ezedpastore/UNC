#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"
#include "weather_utils.h"

void print_help(char *program_name) {
    printf("Usage: %s <input file path>\n\n"
           "Load climate data from a given file in disk.\n"
           "\n"
           "The input file must exist in disk and every line in it must have the following format:\n\n"
           "<year> <month> <day> <temperature> <high> <low> <pressure> <moisture> <precipitations>\n\n"
           "Those elements must be integers and will be copied into the multidimensional integer array 'a'.\n"
           "The dimensions of the array are given by the macro tclimate.\n"
           "\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    filepath = parse_filepath(argc, argv);

    WeatherTable array;

    array_from_file(array, filepath);
    
    int historic_temp_min;
    historic_temp_min = temp_min(array);
    fprintf(stdout, "La menor temperatura minima historica registrada en la provincia de Cordoba es %d\n", historic_temp_min);
    
    int output[YEARS];
    temp_max_of_the_year (array, output);
    for (unsigned int year = 0u; year < YEARS; ++year){
        fprintf(stdout, "La temperatura maxima registrada en el año %u es %d\n", FST_YEAR + year, output[year]);
    }
    
    unsigned int rain_max[YEARS];
    max_rain_of_the_month_of_the_year(array, rain_max);
    for (unsigned int year = 0u; year < YEARS; ++year){
        fprintf(stdout, "El mes en el que se registro la precipitacion maxima en el año %u es %d\n", FST_YEAR + year, rain_max[year]);
    }

    array_dump(array);

    return (EXIT_SUCCESS);
}
