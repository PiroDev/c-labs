#include <stdio.h>

typedef enum
{
    ok = 0,
    args_error = -1
} status_code;

status_code process(int, char **);
status_code create_random_file(int, char *);
status_code print_file(char *);
status_code sort_file(char *);
int get_number_by_pos(int, FILE *f);
void put_number_by_pos(int, int, FILE *f);