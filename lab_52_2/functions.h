#include <stdio.h>
#define MAX_NAME_LEN 30
#define MAX_COMPANY_NAME_LEN 15

typedef enum
{
    ok = 0,
    unknown_args_error = 53,
    args_error = -1,
    file_error = -2,
    input_error = -3
} status_code;

typedef struct
{
    char name[MAX_NAME_LEN + 1];
    char company[MAX_COMPANY_NAME_LEN + 1];
    unsigned int price;
    unsigned int count;
} product;

status_code process(int, char **);
status_code sort_text_file(char *, char *);
status_code find_in_text_file(char *, char *);
status_code add_in_text_file(char *);
product read_item(FILE *, status_code *);
status_code write_item(FILE *, product);
int products_compare(product, product);
int ends_with(char *, char *);
void close_files(FILE **, int);