#include "polynom_functions.h"

#include <stddef.h>  // NULL

#include "list_functions.h"

static int pow_int(int base, int power)
{
    int result = 1;

    while (power != 0)
    {
        if ((power & 1) == 1)
            result *= base;
        power >>= 1;
        base *= base;
    }

    return result;
}

int get_polynom_value(node_t *polynom, int x)
{
    int value = 0;
    while (polynom)
    {
        ratio_t * ratio = (ratio_t *)polynom->data;
        value += ratio->mult * pow_int(x, ratio->power);
        polynom = polynom->next;
    }
    return value;
}

node_t *get_polynom_dif_by_x(node_t *source_polynom)
{
    node_t * result_polynom = source_polynom;

    while (source_polynom)
    {
        ratio_t * ratio = (ratio_t *)source_polynom->data;
        ratio->mult *= ratio->power;
        ratio->power--;
        source_polynom = source_polynom->next;
    }

    return result_polynom;
}

status_code_t get_polynom_sum(node_t *first_polynom, node_t *second_polynom, node_t **result_polynom)
{
    status_code_t result = ok;
    node_t * sum = NULL;

    while (!result && first_polynom && second_polynom)
    {
        ratio_t * first_ratio = (ratio_t *)first_polynom->data;
        ratio_t * second_ratio = (ratio_t *)second_polynom->data;
        int result_power = 0;
        int result_mult = 0;

        if (first_ratio->power == second_ratio->power)
        {
            result_power = first_ratio->power;
            result_mult = first_ratio->mult + second_ratio->mult;

            first_polynom = first_polynom->next;
            second_polynom = second_polynom->next;
        }
        else if (first_ratio->power > second_ratio->power)
        {
            result_power = first_ratio->power;
            result_mult = first_ratio->mult;

            first_polynom = first_polynom->next;
        }
        else
        {
            result_power = second_ratio->power;
            result_mult = second_ratio->mult;

            second_polynom = second_polynom->next;
        }

        node_t * temp = sum;
        if (result_mult != 0)
        {
            sum = push_new_ratio(sum, result_power, result_mult);

            if (!sum)
            {
                result = error_out_of_memory;
                delete_polynom(temp);
            }
        }
        else
        {
            *result_polynom = NULL;
            delete_polynom(sum);
            return error_empty_result;
        }
    }

    node_t * remain = NULL;
    if (first_polynom)
        remain = first_polynom;
    else if (second_polynom)
        remain = second_polynom;

    while (remain)
    {
        int power = ((ratio_t *)remain->data)->power;
        int mult = ((ratio_t *)remain->data)->mult;
        if (mult != 0)
        {
            node_t * temp = sum;
            sum = push_new_ratio(sum, power, mult);
            if (!sum)
            {
                result = error_out_of_memory;
                delete_polynom(temp);
            }
        }
        remain = remain->next;
    }
    *result_polynom = reverse(sum);

    if (!(*result_polynom))
        result = error_empty_result;

    return result;
}

status_code_t divide_polynom(node_t *source_polynom, node_t **even_polynom, node_t **odd_polynom)
{
    status_code_t result = ok;

    while (!result && source_polynom)
    {
        ratio_t * ratio = (ratio_t *)source_polynom->data;
        if (ratio->power % 2 == 0)
        {
            node_t * temp = *even_polynom;
            *even_polynom = push_new_ratio(*even_polynom, ratio->power, ratio->mult);
            if (!(*even_polynom))
            {
                result = error_out_of_memory;
                delete_polynom(temp);
            }
        }
        else
        {
            node_t * temp = *odd_polynom;
            *odd_polynom = push_new_ratio(*odd_polynom, ratio->power, ratio->mult);
            if (!(*odd_polynom))
            {
                result = error_out_of_memory;
                delete_polynom(temp);
            }
        }
        source_polynom = source_polynom->next;
    }

    *even_polynom = reverse(*even_polynom);
    *odd_polynom = reverse(*odd_polynom);

    if (!(*even_polynom) || !(*odd_polynom))
    {
        result = error_empty_result;
        delete_polynom(*even_polynom);
        delete_polynom(*odd_polynom);
    }

    return result;
}
