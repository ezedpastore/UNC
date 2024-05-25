#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; j < length; ++j) {
        if (!goes_before(a[min_pos],a[j])) {
            min_pos = j;
        }
    }
    return (min_pos);
}

void selection_sort(int a[], unsigned int length) {
    for (unsigned int i = 0u; i < length; ++i) {
        unsigned int min_pos = min_pos_from(a, i, length);
        swap(a, i, min_pos);
    }
}


static void insert(int a[], unsigned int i) {
    unsigned int j; 
    j = i;
    
    while((j>0) && (false == goes_before(a[j-1], a[j]))){
        swap(a, j-1, j);
        j = j - 1;   
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        insert(a, i);
    }
}


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv, i, j;
    
    ppiv = izq;
    i = izq + 1;
    j = der;

    while(i <= j){
        if((goes_before(a[i], a[ppiv]) == false) && (goes_before(a[ppiv], a[j]) == false)){
            swap(a, i, j);
        }
        if(goes_before(a[i], a[ppiv])){
            i = i + 1;
        }
        if(goes_before(a[ppiv], a[j])){
            j = j - 1;
        }
    }        
    swap(a, ppiv, j);
    ppiv = j;

    return ppiv;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv;

    if(der > izq){
        ppiv = partition(a, izq, der);
        if(ppiv > 0){
            quick_sort_rec(a, izq, ppiv-1);
            quick_sort_rec(a, ppiv+1, der);
        }
        else{
            quick_sort_rec(a, izq, 0);
            quick_sort_rec(a, ppiv + 1, der);
        }
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}
