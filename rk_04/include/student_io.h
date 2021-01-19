#ifndef STUDENT_IO_H_
#define STUDENT_IO_H_

#include "student.h"
#include <stdio.h>

student_t *read_student(FILE *f);
void print_mark(void *data);
void print_student(void *data);

#endif  // STUDENT_IO_H_
