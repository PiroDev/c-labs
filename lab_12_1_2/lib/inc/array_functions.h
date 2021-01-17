#ifndef ARRAY_FUNCTIONS_H_
#define ARRAY_FUNCTIONS_H_

#include <stddef.h>

void array_shift_left(int *array, size_t array_size, size_t shift);

int array_fill_full_squares(int *src_array, size_t src_size, int *dest_array);

#endif  // ARRAY_FUNCTIONS_H_
