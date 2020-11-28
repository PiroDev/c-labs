#ifndef POLYNOM_IO_H_
#define POLYNOM_IO_H_

#include "status_codes.h"
#include "polynom.h"

#define CMD_LEN 3

typedef enum
{
    calculate,
    dif_by_x,
    sum,
    divide
} command_t;

status_code_t read_command(command_t *command);
status_code_t read_polynom(node_t **polynom);
status_code_t read_polynom_point(int *polynom_point);
void print_polynom_value(int value);
void print_polynom(node_t *polynom);

#endif  // POLYNOM_IO_H_
