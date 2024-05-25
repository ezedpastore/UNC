#ifndef _COUNTER_H
#define _COUNTER_H

#include <stdbool.h>

typedef struct _counter * counter;

counter counter_init(void);

void counter_inc(counter c);

bool counter_is_init(counter c);

void counter_dec(counter c);

counter counter_copy(counter c);

void counter_destroy(counter c);

#endif
