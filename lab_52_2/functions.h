#include <stdio.h>
#define MAX_NAME_LEN 30
#define MAX_COMPANY_NAME_LEN 15

typedef enum
{
    ok = 0,
    args_error = 53,
    file_error = 54,
    input_error = 55
} status_code;

typedef struct
{
    char name[MAX_NAME_LEN + 1];
    char company[MAX_COMPANY_NAME_LEN + 1];
    int price;
    int count;
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