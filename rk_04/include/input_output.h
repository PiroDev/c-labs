#ifndef INPUT_OUTPUT_H_
#define INPUT_OUTPUT_H_

#include "list.h"

void print_list(node_t *head, void (*print_data)(void *data));
void print_commands(void);
int read_command(void);

#endif  // INPUT_OUTPUT_H
