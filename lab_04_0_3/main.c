#include <string.h>
#include <stdio.h>
#include "my_string.h"

status_code string_process(char[STR_MAX_LEN / 2 - 1][WORD_MAX_LEN + 1], int, char[]);

int main()
{
    char words[STR_MAX_LEN / 2 - 1][WORD_MAX_LEN + 1] = { '\0' };
    int words_count = 0;
    status_code result = str_input(words, &words_count);
    if (result == ok)
    {
        char new_str[STR_MAX_LEN] = { '\0' };
        result = string_process(words, words_count, new_str);
        if (result != ok)
            printf("Error!");
        else
            printf("Result: %s\n", new_str);
    }
    else
        printf("Error!");
    return result;
}

status_code string_process(char words[STR_MAX_LEN / 2 - 1][WORD_MAX_LEN + 1], int words_count, char new_str[])
{
    status_code result = ok;
    for (int i = words_count - 1; i >= 0; i--)
        if (strcmp((const char *) words[i], (const char *) words[words_count - 1]) != 0)
        {
            exclude(words[i], words[i][0], 1);
            if (strcmp((const char *) new_str, "") != 0)
                strcat(new_str, " ");
            strcat(new_str, (const char *) words[i]);
        }
    if (strcmp((const char *) new_str, "") == 0)
        result = items_error;
    return result;
}