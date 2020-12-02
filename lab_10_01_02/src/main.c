#include "../include/polynom_io.h"
#include "../include/polynom_functions.h"

#include <stddef.h>

int main(void)
{
    status_code_t result = ok;

    command_t command;
    result = read_command(&command);

    node_t *source_polynom = NULL;
    if (!result)
        result = read_polynom(&source_polynom);

    if (!result)
    {
        int polynom_point = 0;
        int value = 0;
        node_t *result_polynom = NULL;
        node_t *even_polynom = NULL;
        node_t *odd_polynom = NULL;

        switch (command)
        {
            case calculate:
                result = read_polynom_point(&polynom_point);
                if (!result)
                {
                    value = get_polynom_value(source_polynom, polynom_point);
                    print_polynom_value(value);
                }
                break;
            case dif_by_x:
                result_polynom = get_polynom_dif_by_x(source_polynom);
                source_polynom = NULL;
                break;
            case sum:
                result = error_empty_result;
                // result = read_polynom(&result_polynom);
                // if (!result)
                // {
                //     node_t *temp = NULL;
                //     result = get_polynom_sum(source_polynom, result_polynom, &temp);
                //     delete_polynom(result_polynom);
                //     result_polynom = temp;
                // }
                break;
            case divide:
                result = divide_polynom(source_polynom, &even_polynom, &odd_polynom);
                if (!result)
                {
                    print_polynom(even_polynom);
                    delete_polynom(even_polynom);
                    result_polynom = odd_polynom;
                }
                break;
            default:
                break;
        }

        if (!result && result_polynom)
            print_polynom(result_polynom);

        delete_polynom(result_polynom);
    }

    delete_polynom(source_polynom);

    return result;
}