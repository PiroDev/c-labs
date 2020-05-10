#include <stdio.h>

#define OK 0
#define ARGS_ERROR -1
#define FILE_ERROR -2

int process(int, char **);
int create_random_file(int, char *);
int print_file(char *);
int sort_file(char *);
int get_number_by_pos(int, FILE *f, int *);
void put_number_by_pos(int, int, FILE *f, int *);