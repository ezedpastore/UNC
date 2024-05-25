#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void absolute(int x, int *y) {
    if (x >= 0){
        *y = x;
    }
    else{
        *y = -x;
    }
}

int main(void) {
    int a=0, res=0;  
    a = -10;
    
    absolute(a, &res);
    
    printf("res = %d\n", res);
    
    assert(res >= 0 && (res == a || res == -a));
    return EXIT_SUCCESS;
}

/*
El parametro int *y de absolute es de tipo in/out ya que puedo leer y escribir en la variable.
Todas los parametros son de tipo in/out en C, ya que puedo leerlos y sobreescribirlos tambien.
*/