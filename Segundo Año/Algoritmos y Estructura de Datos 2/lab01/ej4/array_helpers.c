#include "array_helpers.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {
    FILE *archivo;
    archivo = fopen(filepath, "r");
    
    unsigned int length;
    
    if (fscanf(archivo, "%u", &length) != 1 || length > max_size || length == 0){
        printf("Error, el tamaño del arreglo es incorrecto\n");
        fclose(archivo);
        exit(EXIT_FAILURE);
    }

    for (unsigned int i = 0; i < length; i++){
        if (fscanf(archivo, "%d", &array[i]) != 1){
            printf("Error, el tamaño del arreglo no coincide con la cantidad de elementos en el\n");
            fclose(archivo);
            exit(EXIT_FAILURE);
        }
    }

    fclose(archivo);
    
    return length;
}

bool array_is_sorted(int a[], unsigned int length){
    bool b = true;
    unsigned int i = 0;

    while (i < (length - 1) && b){
        if (a[i] >= a[i + 1]){
            b = false;
        }
        i += 1;
    }
    
    return b;
}

void array_dump(int a[], unsigned int length) {

    printf("[");
    for(unsigned int i = 0; i < length; i++){
        printf("%d", a[i]);
        if(i < length -1){
            printf(",");
        }
    }
    printf("]\n");
}
