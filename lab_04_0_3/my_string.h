#define STR_MAX_LEN 256
#define WORD_MAX_LEN 16

typedef enum
{
    ok = 0,
    len_error = 1,
    items_error = 2
} status_code;

typedef enum
{
    false = 0,
    true = 1
} bool;

status_code str_input(char[STR_MAX_LEN / 2 - 1][WORD_MAX_LEN + 1], int *);
bool in(char *, char);
void exclude(char *, char, int);