#ifndef _PAIR_H
#define _PAIR_H

typedef struct s_pair_t * pair_t;
typedef int elem;

pair_t pair_new(elem x, elem y);

elem pair_first(pair_t p);

elem pair_second(pair_t p);

pair_t pair_swapped(pair_t p);

pair_t pair_destroy(pair_t p);

#endif
