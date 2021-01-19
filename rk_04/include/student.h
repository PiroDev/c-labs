#ifndef STUDENT_H_
#define STUDENT_H_

#include <stddef.h>
#include "list.h"

typedef struct
{
    char *name;
    int age;
    node_t *marks;
} student_t;

student_t *new_student(const char *name, int age, int *marks, size_t marks_count);
void delete_student(void *data);

#endif  // STUDENT_H_
