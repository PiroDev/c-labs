#include "../include/polynom.h"
#include "../include/list_functions.h"

#include <stdlib.h>

ratio_t *new_ratio(int power, int mult)
{
    ratio_t *ratio = malloc(sizeof(ratio_t));
    if (ratio)
    {
        ratio->power = power;
        ratio->mult = mult;
    }
    return ratio;
}

node_t *push_new_ratio(node_t *polynom, int power, int mult)
{
    node_t *result_polynom = NULL;
    ratio_t *ratio = new_ratio(power, mult);
    if (ratio)
    {
        result_polynom = push_front(polynom, ratio);
        if (!result_polynom)
            delete_polynom(polynom);
    }
    return result_polynom;
}

void delete_polynom(node_t *polynom)
{
    while (polynom)
    {
        ratio_t *ratio = pop_front(&polynom);
        free(ratio);
    }
}

