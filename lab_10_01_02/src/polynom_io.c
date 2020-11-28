#include "../include/polynom_io.h"
#include "../include/list_functions.h"

#include <stdio.h>
#include <string.h>

status_code_t read_command(command_t *command)
{
    status_code_t result = ok;

    char choice[CMD_LEN + 2] = { '\0' };
    fgets(choice, CMD_LEN + 2, stdin);

    if (!strcmp(choice, "val\n"))
        *command = calculate;
    else if (!strcmp(choice, "ddx\n"))
        *command = dif_by_x;
    else if (!strcmp(choice, "sum\n"))
        *command = sum;
    else if (!strcmp(choice, "dvd\n"))
        *command = divide;
    else
        result = error_unknown_arg;
    
    return result;
}

status_code_t read_polynom(node_t **polynom)
{
    status_code_t result = ok;

    int mult = 0;
    int power = 0;
    char c = 0;
    while (!result && scanf("%d %d%c", &mult, &power, &c) == 3)
    {
        ratio_t *ratio = new_ratio(power, mult);
        if (ratio)
        {
            node_t *temp = *polynom;
            *polynom = push_front(*polynom, ratio);
            if (!(*polynom))
            {
                result = error_out_of_memory;
                delete_polynom(temp);
                *polynom = NULL;
            }
        }
        else
        {
            result = error_out_of_memory;
            delete_polynom(*polynom);
        }
        if (c == '\n' || c == EOF)
            break;
    }

    if (!c)
    {
        result = error_wrong_input;
        delete_polynom(*polynom);
    }
    else
        *polynom = reverse(*polynom);

    return result;
}

status_code_t read_polynom_point(int *polynom_point)
{
    status_code_t result = ok;
    if (scanf("%d", polynom_point) != 1)
        result = error_wrong_input;
    return result;
}

void print_polynom_value(int value)
{
    printf("%d\n", value);
}

status_code_t print_polynom(node_t *polynom)
{
    status_code_t result = 0;

    int count = 0;
    while (polynom)
    {
        ratio_t *ratio = (ratio_t *)polynom->data;
        if (ratio->power >= 0)
            printf("%d %d ", ratio->mult, ratio->power);
        polynom = polynom->next;
        count++;
    }
    if (count)
        printf("L\n");
    else
        result = error_empty_result;

    return result;
}

