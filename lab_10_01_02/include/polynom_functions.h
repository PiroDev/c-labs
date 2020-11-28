#ifndef POLYNOM_FUNCTIONS_H_
#define POLYNOM_FUNCTIONS_H_

#include "polynom.h"
#include "status_codes.h"

int get_polynom_value(node_t *polynom, int x);
node_t *get_polynom_dif_by_x(node_t *source_polynom);
status_code_t get_polynom_sum(node_t *first_polynom, node_t *second_polynom, node_t **result_polynom);
status_code_t divide_polynom(node_t *source_polynom, node_t **even_polynom, node_t **odd_polynom);

#endif  // POLYNOM_FUNCTIONS_H_
