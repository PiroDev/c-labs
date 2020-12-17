#include "list_functions.h"

#include <stddef.h>
#include <stdlib.h>

node_t *list_push_back(node_t *head, void *data)
{
    if (data)
    {
        if (!head)
        {
            head = new_node(data);
        }
        else
        {
            node_t *curr = head;
            while (curr->next)
            {
                curr = curr->next;
            }
            curr->next = new_node(data);
        }
    }

    return head;
}

node_t *list_pop_back(node_t *head)
{
    node_t *new_head = head;

    if (head)
    {
        node_t *prev = NULL;
        while (head->next)
        {
            prev = head;
            head = head->next;
        }
        free(head);
        if (prev)
            prev->next = NULL;
        else
            new_head = NULL;
    }

    return new_head;
}
