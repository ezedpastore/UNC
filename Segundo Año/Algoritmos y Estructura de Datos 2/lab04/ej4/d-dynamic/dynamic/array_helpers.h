#ifndef _ARRAY_HELPERS_H
#define _ARRAY_HELPERS_H

#include <stdlib.h>
#include <stdbool.h>

void array_dump(int a[], size_t length);

int *array_from_file(const char *filepath, size_t *length);

#endif
