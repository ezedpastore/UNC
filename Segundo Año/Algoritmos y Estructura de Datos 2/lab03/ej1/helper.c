#include <stdbool.h>
#include "helper.h"

unsigned int pos (unsigned int indexes[], unsigned int length, unsigned int j){
    unsigned int i, ubic;
    i = 0;
    bool b = true;
    
    while(i < length && b){
        if (indexes[i] < length){
            if (indexes[i] == j){
                ubic = i;
                b = false;
            }
            else{
                i = i + 1;
            }
        }
        else{
            indexes[i] = j;
        }
    }
    
    

    return ubic;
}