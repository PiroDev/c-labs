#include "../include/list.h"

#include <stdlib.h>

node_t *new_node(void *data)
{
    node_t* new_node = malloc(sizeof(node_t));
    if (new_node)
    {
        new_node->data = data;
        new_node->next = NULL;
    }
    return new_node;
}
