#include "list.h"

#include <stdlib.h>

node_t *new_node(void *data)
{
    node_t *node = malloc(sizeof(node_t));
    if (node) {
        node->data = data;
        node->next = NULL;
    }
    return node;
}

void delete_list(node_t *head, void (*delete_data)(void *))
{
    node_t *next = NULL;
    while (head)
    {
        next = head->next;
        delete_data(head->data);
        free(head);
        head = next;
    }
}
