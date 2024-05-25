#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y){
    bool b;
    
    if (x->rank <= y->rank){
        b = true;
    }
    else{
        b = false;
    }
    
    return b;
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

void swap(player_t atp[], unsigned int i, unsigned int j){
    player_t temp = NULL;
    temp = malloc(sizeof(struct _player_t));
    *temp = *atp[i];
    *atp[i] = *atp[j];
    *atp[j] = *temp;
}

unsigned int partition(player_t atp[], unsigned int izq, unsigned int der) {
    unsigned int ppiv, i, j;
    
    ppiv = izq;
    i = izq + 1;
    j = der;

    while(i <= j){
        if((goes_before(atp[i], atp[ppiv]) == false) && (goes_before(atp[ppiv], atp[j]) == false)){
            swap(atp, i, j);
        }
        if(goes_before(atp[i], atp[ppiv])){
            i = i + 1;
        }
        if(goes_before(atp[ppiv], atp[j])){
            j = j - 1;
        }
    }        
    swap(atp, ppiv, j);
    ppiv = j;

    return ppiv;
}

void quick_sort_rec(player_t atp[], unsigned int izq, unsigned int der) {
    unsigned int ppiv;

    if(der > izq){
        ppiv = partition(atp, izq, der);
        if(ppiv > 0){
            quick_sort_rec(atp, izq, ppiv-1);
            quick_sort_rec(atp, ppiv+1, der);
        }
        else{
            quick_sort_rec(atp, izq, 0);
            quick_sort_rec(atp, ppiv + 1, der);
        }
    }
}

void quick_sort(player_t atp[], unsigned int length) {
    quick_sort_rec(atp, 0u, (length == 0u) ? 0u : length - 1u);
}

void sort(player_t a[], unsigned int length) {
    quick_sort(a, length);
}

