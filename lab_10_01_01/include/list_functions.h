#ifndef LIST_FUNCTIONS_H_
#define LIST_FUNCTIONS_H_

#include "list.h"

node_t *push_front(node_t *head, void *data);
void insert(node_t **head, node_t *element, node_t *before);
void *pop_front(node_t **head);
node_t *reverse(node_t *head);
void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *));
node_t *sort(node_t *head, int (*comparator)(const void *, const void *));

#endif  // LIST_FUNCTIONS_H_
