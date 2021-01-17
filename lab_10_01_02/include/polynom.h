#ifndef POLYNOM_H_
#define POLYNOM_H_

#include "list.h"

typedef struct
{
    int power;
    int mult;
} ratio_t;

ratio_t *new_ratio(int power, int mult);
node_t *push_new_ratio(node_t *polynom, int power, int mult);
void delete_polynom(node_t *polynom);

#endif  // POLYNOM_H_
