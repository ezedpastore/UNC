#ifndef _SORT_H
#define _SORT_H
#include <stdbool.h>
#include "player.h"

bool goes_before(player_t x, player_t y);

void swap(player_t atp[], unsigned int i, unsigned int j);

void insert(player_t atp[], unsigned int i);

void insertion_sort(player_t atp[], unsigned int length);

bool array_is_sorted(player_t atp[], unsigned int length);

void sort(player_t a[], unsigned int length);

#endif
