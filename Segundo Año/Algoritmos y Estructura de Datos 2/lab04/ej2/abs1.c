#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    if (x >= 0){
        y = x;
    }
    else{
        y = -x;
    }
}

int main(void) {
    int a, res; 
    res = 0;
    a = -10;
    
    absolute(a, res);
    
    printf("res = %d\n", res);

    return EXIT_SUCCESS;
}

/*
El valor que se muestra por pantalla es res = 0, mientras que el resultado espe-
rado en el lenguaje de la materia es -10. Esto es debido a que el comportamien-
to de las funciones en C es distinto al comportamiento de funciones y procedi-
mientos en el lenguaje de la materia
*/

