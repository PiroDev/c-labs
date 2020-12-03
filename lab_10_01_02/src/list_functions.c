#include "../include/list_functions.h"

#include <stdlib.h>

node_t *push_front(node_t *head, void *data)
{
    node_t *new_head = new_node(data);
    if (new_head)
        new_head->next = head;
    return new_head;
}

void insert(node_t **head, node_t *element, node_t *before)
{
    if (head && element)
    {
        if (*head != before)
        {
            node_t *curr = *head;
            while (curr->next && curr->next != before)
                curr = curr->next;
            if (curr->next == before)
            {
                curr->next = element;
                element->next = before;
            }
        }
        else
        {
            element->next = *head;
            *head = element;
        }
    }
}

void *pop_front(node_t **head)
{
    void *data = NULL;

    if (head && *head)
    {
        node_t *old_head = *head;
        data = old_head->data;
        *head = old_head->next;
        free(old_head);
    }

    return data;
}

node_t *reverse(node_t *head)
{
    node_t *new_head = NULL;
    while (head)
        new_head = push_front(new_head, pop_front(&head));
    return new_head;
}
