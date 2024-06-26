#ifndef _SORT_H
#define _SORT_H
#include <stdbool.h>
#include "player.h"

bool goes_before(player_t x, player_t y);

bool array_is_sorted(player_t atp[], unsigned int length);

void sort(player_t a[], unsigned int length);

void quick_sort(player_t atp[], unsigned int length);

void quick_sort_rec(player_t atp[], unsigned int izq, unsigned int der);

unsigned int partition(player_t atp[], unsigned int izq, unsigned int der);

#endif
