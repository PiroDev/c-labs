#ifndef LIST_H_
#define LIST_H_

typedef struct node
{
    void *data;
    struct node *next;
} node_t;

node_t *new_node(void *data);
void delete_list(node_t *head, void (*delete_data)(void *));

#endif  // LIST_H_
