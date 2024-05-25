#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "helper.h"

#define MAX_SIZE 1000

void print_help(char *program_name) {
    printf("Usage: %s <input file path>\n\n"
           "Loads an array given in a file in disk and prints it on the screen."
           "\n\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    char *result = NULL;
    bool valid_args_count = (argc == 2);

    if (!valid_args_count) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size){
    unsigned int i, length;
    i = 0;
    FILE *archivo = fopen(path, "r");

    while(fscanf(archivo, "%u -> *%c*", &indexes[i], &letters[i]) != EOF){
        i = i + 1;
    }
    
    length = i;

    if (max_size < length){
        exit(EXIT_FAILURE);
        fclose(archivo);
    }

    return length;    
}

int main(int argc, char *argv[]){
    char *filepath = NULL;

    filepath = parse_filepath(argc, argv);
    
    
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length=0;
    unsigned int i, k;
    i = 0;
    
    length = data_from_file(filepath, indexes, letters, MAX_SIZE);
     
    while(i < length){
        k = pos(indexes, length, i); 
        sorted[i] = letters[k];
        i = i + 1;
    }
    
    dump(sorted, length);

    return EXIT_SUCCESS;
}

