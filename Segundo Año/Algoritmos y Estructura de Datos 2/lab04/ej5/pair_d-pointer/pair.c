#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pair.h"

struct s_pair_t {
    int fst;
    int snd;
};

pair_t pair_new(int x, int y){
    pair_t p = NULL;
    p = malloc(sizeof(struct s_pair_t));
    p->fst = x;
    p->snd = y;
    assert(p->fst && p->snd);

    return p;
}

int pair_first(pair_t p){
    assert(p->fst && p->snd);
    int x;
    x = p->fst;
    assert(p->fst == x);

    return x;
}

int pair_second(pair_t p){
    assert(p->fst && p->snd);
    int y;
    y = p->snd;
    assert(p->snd == y);

    return y;
}

pair_t pair_swapped(pair_t p){
    assert(p->fst && p->snd);
    pair_t q = NULL;
    q = malloc(sizeof(struct s_pair_t));
    q->fst = p->snd;
    q->snd = p->fst;
    assert(q->fst == p->snd && q->snd == p->fst);

    return q;
}

pair_t pair_destroy(pair_t p){
    free(p);

    return p;
}