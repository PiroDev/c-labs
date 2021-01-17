#ifndef LIST_H_
#define LIST_H_

typedef struct node node_t;

struct node
{
    void *data;
    node_t *next;
};

node_t *new_node(void *data);

#endif  // LIST_H_
