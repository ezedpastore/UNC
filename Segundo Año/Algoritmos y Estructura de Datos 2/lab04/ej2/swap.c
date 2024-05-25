#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void swap(int *a, int *b){
    int aux; 
    
    aux = *a;
    *a = *b;
    *b = aux;
}


int main(void){
    int x, y;
    x = 6;
    y = 4;
    
    printf("Antes del swap: x = %d and y = %d\n", x, y);
    
    swap(&x, &y);
    
    printf("Despues del swap: x = %d and y = %d\n", x, y);
    
    exit(EXIT_SUCCESS);
}

