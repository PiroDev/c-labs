#include <stdio.h>
#include "my_string.h"

status_code str_input(char words[STR_MAX_LEN / 2 - 1][WORD_MAX_LEN + 1], int *words_count)
{
    *words_count = 0;
    int len = 0;
    char *sep = " ,.;:-!?";
    char ch = 0;
    char ch_prev = 0;
    int word_index = 0;
    int symbol_index = 0;
    while (((ch = getchar()) != '\n') && (ch != EOF))
    {
        if (in(sep, ch) == false)
        {
            if (symbol_index < WORD_MAX_LEN - 1)
            {
                words[word_index][symbol_index] = ch;
                symbol_index++;
            }
            else
                return len_error;
        }
        else
        {
            if (symbol_index != 0)
            {
                symbol_index = 0;
                word_index++;
            }
        }
        len++;
        ch_prev = ch;
        if (len >= STR_MAX_LEN)
            return len_error;
    }
    if (word_index + symbol_index == 0)
        return items_error;
    if (in(sep, ch_prev) == true)
        word_index--;
    *words_count = word_index + 1;
    return ok;
}

bool in(char *str, char symbol)
{
    bool result = false;
    int i = 0;
    while ((str[i] != '\0') && (result == false))
    {
        if (str[i] == symbol)
            result = true;
        i++;
    }
    return result;
}

void exclude(char *str, char symbol, int start)
{
    int i = start;
    while (str[i] != '\0')
    {
        if (str[i] == symbol)
            {
                int j = i;
                do
                {
                    str[j] = str[j + 1];
                    j++;
                }
                while (str[j - 1] != '\0');
            }
        if (str[i] != '\0')
            i++;
    }
}