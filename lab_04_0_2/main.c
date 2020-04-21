#include <string.h>
#include <stdio.h>
#include "my_string.h"

void unique_words(char[STR_MAX_LEN / 2 - 1][WORD_MAX_LEN + 1], int[], int);

int main()
{
    char words[STR_MAX_LEN / 2 - 1][WORD_MAX_LEN + 1] = { '\0' };
    int words_count = 0;
    status_code result = str_input(words, &words_count);
    if (result == ok)
    {
        int repeats[STR_MAX_LEN / 2 - 1] = { 0 };
        unique_words(words, repeats, words_count);
        printf("Result:\n");
        for (int i = 0; i < words_count; i++)
            printf("%s %d\n", words[i], repeats[i]);
        return result;
    }
    printf("Error!");
    return result;
}

void unique_words(char words[STR_MAX_LEN / 2 - 1][WORD_MAX_LEN + 1], int repeats[], int words_count)
{
    for (int i = 0; i < words_count; i++)
        repeats[i] = 1;
    for (int i = 0; i < words_count; i++)
        for (int j = i + 1; j < words_count; j++)
        {
            if ((repeats[i] != 0) && (strcmp((const char *) words[i], (const char *) words[j]) == 0))
            {
                repeats[i]++;
                repeats[j]++;
            }
        }
}