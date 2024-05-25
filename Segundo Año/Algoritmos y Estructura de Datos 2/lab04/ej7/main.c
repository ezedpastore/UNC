#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"
#include "list.h"

static const unsigned int MAX_SIZE = 100000u;

void print_help(char *program_name) {
    printf("Usage: %s <input file path>\n\n"
           "Compute average for the list of numbers in file.\n"
           "\n",
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


float average(list l) {
    float x, sum;
    sum = 0.00;
    
    unsigned int large = length(l);
    
    float prom;
    
    list aux;
    aux = copy_list(l);

    while(!is_empty(aux)){
        x = head(aux);
        sum = sum + x;
        aux = tail(aux);
    }
    destroy(aux);
    
    prom = sum / large;

    return prom;
}

list array_to_list(int array[], unsigned int length) {
    list l = empty();
    
    for (unsigned int i = 0u; i < length; ++i) {
        l = addr(l, array[i]);
    }
    
    return l;
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    filepath = parse_filepath(argc, argv);

    int array[MAX_SIZE];

    unsigned int length = array_from_file(array, MAX_SIZE, filepath);

    array_dump(array, length);

    list l = array_to_list(array, length);

    printf("The average is: %.2f \n", average(l));

    return (EXIT_SUCCESS);
}
