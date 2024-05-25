#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int i, tam;
    i = 0;

    while(s[i] != '\0'){
        i += 1;
    }
    
    tam = i;

    return tam;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    bool b;
    b = true;
    unsigned int i;
    i = 0;
    
    while((s1[i] != '\0' || s2[i] != '\0') && b){
        if(s1[i] != '\0' && s2[i] == '\0'){
            b = false;
        }
        if(s1[i] == '\0' && s2[i] != '\0'){
            b = false;
        }
        if(s1[i] == s2[i]){
            b = true;
        }
        else{
            b = false;
        }
        i += 1;
    }

    return b;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
  
  unsigned int size_s1 = fstring_length(s1);
  unsigned int size_s2 = fstring_length(s2);
  
  unsigned int i = 0;
  
  while (i < size_s1 && i < size_s2){
      char x = s1[i];
      char y = s2[i];
    
      if (x < y){ 
          return true;
      }
      else if (x > y){
          return false;
      }
      
      i++;
  }
  
  return size_s1 <= size_s2;
}


