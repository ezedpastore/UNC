#ifndef _PAIR_H
#define _PAIR_H

typedef struct s_pair_t * pair_t;

pair_t pair_new(int x, int y);

int pair_first(pair_t p);

int pair_second(pair_t p);

pair_t pair_swapped(pair_t p);

pair_t pair_destroy(pair_t p);

#endif

