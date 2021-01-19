#define _GNU_SOURCE

#include "student.h"
#include "list_functions.h"

#include <stdlib.h>
#include <string.h>

student_t *new_student(const char *name, int age, int *marks, size_t marks_count)
{
    student_t *student = malloc(sizeof(student_t));

    if (student)
    {
        student->name = strdup(name);
        student->age = age;
        for (size_t i = 0; i < marks_count; i++)
        {
            student->marks = list_push_back(student->marks, marks + i);
        }
    }

    return student;
}

void delete_mark(void *data)
{
    int *mark = (int *) data;
    *mark += 1;
}

void delete_student(void *data)
{
    student_t *student = (student_t *) data;
    if (student)
    {
        free(student->name);
        delete_list(student->marks, delete_mark);
    }
    free(student);
}
