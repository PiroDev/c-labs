#define _GNU_SOURCE

#include "student_io.h"
#include "input_output.h"

#include <stdlib.h>
#include <string.h>

int *read_marks(FILE *f, size_t *count)
{
    int *marks = NULL;
    if (f)
    {
        printf("Введите количество оценок: ");
        scanf("%zu", count);
        if (*count > 0)
        {
            marks = calloc(*count, sizeof(int));
            int res = 1;
            printf("Введите оценки:\n");
            for (size_t i = 0; res == 1 && i < *count; i++)
            {
                res = scanf("%d", marks + i);
            }

            if (res != 1)
            {
                printf("Некорректное значение!\n");
                free(marks);
                marks = NULL;
                *count = 0;
            }
        }
        else
        {
            printf("Некорректное значение!\n");
        }
    }

    return marks;
}

student_t *read_student(FILE *f)
{
    student_t *student = NULL;

    if (f)
    {
        printf("Введите имя студента: ");
        scanf("%*[\n]");
        char *name = NULL;
        size_t n = 0;
        if (getline(&name, &n, f) != -1)
        {
            if (name[strlen(name) - 1] == '\n')
                name[strlen(name) - 1] = '\0';

            int age = -1;
            printf("Введите возраст студента: ");
            if (scanf("%d", &age) == 1 && age > 0)
            {
                n = 0;
                int *marks = read_marks(f, &n);
                if (n > 0)
                    student = new_student(name, age, marks, n);

                free(name);
            }
        }
        else
        {
            printf("Не удалось прочитать имя!\n");
        }

    }

    return student;
}

void print_mark(void *data)
{
    printf("%d", *((int *)data));
}

void print_student(void *data)
{
    student_t *student = (student_t *) data;
    printf("{ %s, %d лет, оценки: ", student->name, student->age);
    print_list(student->marks, print_mark);
    printf(" }");
}
