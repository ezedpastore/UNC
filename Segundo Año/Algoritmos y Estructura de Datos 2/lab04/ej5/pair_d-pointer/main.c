#include <stdlib.h>  
#include <stdio.h>   
#include "pair.h"    

static
void show_pair(pair_t p) {
    int x, y;
    x = pair_first(p);
    y = pair_second(p);
    printf("(%d, %d)\n", x, y);
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
La implementacion si logra el encapsulamiento debido a que en el archivo de
cabecera pair.h no se muestra como estan definidos los campos del struct y 
por lo tanto el usuario que use mi libreria no va a saber con que implemente 
a mis funciones.
*/
