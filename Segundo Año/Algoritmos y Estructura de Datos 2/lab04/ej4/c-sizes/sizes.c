#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    data_t messi = {"Leo Messi", 36, 169};
    print_data(messi);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n", sizeof(messi.name), sizeof(messi.age), sizeof(messi.height), sizeof(messi));
    
    printf("\n");

    printf("name-direction  : %p \n"
           "age-direction   : %p \n"
           "height-direction: %p \n"
           "data_t-direction: %p \n", (void *) &messi.name, (void *) &messi.age, (void *) &messi.height, (void *) &messi);

    return EXIT_SUCCESS;
}

/*
La direccion del campo name es la misma direccion que tiene la estructura com-
pleta, pero eso supongo que se debe a que el campo name es el primer elemento
del struct y ambas direcciones estan al comienzo del struct.
*/

