#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pair.h"

pair_t pair_new(int x, int y){
    pair_t p;
    p.values[0] = x;
    p.values[1] = y;
    assert(p.values[0] && p.values[1]);

    return p;
}

int pair_first(pair_t p){
    assert(p.values[0] && p.values[1]);
    int x;   
    x = p.values[0];
    assert(p.values[0] == x);

    return x;
}

int pair_second(pair_t p){
    assert(p.values[0] && p.values[1]);
    int y;
    y = p.values[1];
    assert(p.values[1] == y);

    return y;
}

pair_t pair_swapped(pair_t p){
    assert(p.values[0] && p.values[1]);
    pair_t q;
    q.values[0] = p.values[1];
    q.values[1] = p.values[0];
    assert(q.values[0] == p.values[1] && q.values[1] == p.values[0]);

    return q;
}

pair_t pair_destroy(pair_t p){
    p.values[0] = 0;
    p.values[1] = 0;

    return p;
}