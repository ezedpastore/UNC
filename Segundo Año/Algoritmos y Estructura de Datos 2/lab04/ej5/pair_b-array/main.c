#include <stdlib.h> 
#include <stdio.h>   
#include "pair.h"    

static
void show_pair(pair_t p) {
    printf("(%d, %d)\n", p.values[0], p.values[1]);
}

int main(void) {
    pair_t p, q;
   
    p = pair_new(3, 4);
    
    printf("p = ");
    show_pair(p);
    
    q = pair_swapped(p);
    
    printf("q = ");
    show_pair(q);
    
    p = pair_destroy(p);
    q = pair_destroy(q);
    return EXIT_SUCCESS;
}

/*
Falla porque los campos del struct del apartado b(values) son diferentes a los campos
del struct del apartado a(fst,snd).
*/

/*
No se logra el encapsulamiento del TAD debido a que en el archivo de cabecera pair.h
esta especificado el struct y su campo, por lo que el usuario que utilize esta libreria
va a saber con que elementos se implementaron las funciones.
*/