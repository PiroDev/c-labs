#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

#define MIN_RAND -100
#define MAX_RAND 100

int process(int argc, char **argv)
{
    int result = OK;
    if (argc < 3)
        result = ARGS_ERROR;
    else
    {
        if ((strcmp((const char *) argv[1], "c") == 0) && (argc == 4))
        {
            int n;
            if (((n = atoi(argv[2])) != 0) && (n > 0))
                result = create_random_file(n, argv[3]);
            else
                result = ARGS_ERROR;
        }
        else if ((strcmp((const char *) argv[1], "p") == 0) && (argc == 3))
        {
            result = print_file(argv[2]);
        }
        else if ((strcmp((const char *) argv[1], "s") == 0) && (argc == 3))
        {
            result = sort_file(argv[2]);
        }
        else
        {
            result = ARGS_ERROR;
        }
    }
    return result;
}

int create_random_file(int n, char *file_name)
{
    int result = OK;
    FILE *f = NULL;
    f = fopen((const char *) file_name, "wb");
    if (f != NULL)
    {
        int num;
        srand(time(NULL));
        for (int i = 0; i < n; i++)
        {
            num = MIN_RAND + rand() % ((MAX_RAND + 1) - MIN_RAND);
            if (fwrite(&num, sizeof(int), 1, f) != 1)
            {
                result = FILE_ERROR;
                break;
            }
        }
        fclose(f);
    }
    else
        result = ARGS_ERROR;
    return result;
}

int print_file(char *file_name)
{
    int result = OK;
    FILE *f = NULL;
    f = fopen((const char *) file_name, "rb");
    if (f != NULL)
    {
        int num;
        while (fread(&num, sizeof(int), 1, f) == 1)
            printf("%d ", num);
        if (!feof(f))
            result = FILE_ERROR;
        fclose(f);
    }
    else
        result = ARGS_ERROR;
    return result;
}

int sort_file(char *file_name)
{
    int result = OK;
    FILE *f = NULL;
    f = fopen((const char *) file_name, "r+b");
    if (f != NULL)
    {
        fseek(f, 0, SEEK_END);
        int n = ftell(f) / sizeof(int);
        fseek(f, 0, SEEK_SET);
        int num_i, num_j, temp;
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
            {
                num_i = get_number_by_pos(i, f, &result);
                num_j = get_number_by_pos(j, f, &result);
                if (result != OK)
                {
                    fclose(f);
                    return result;
                }
                if (num_i >= num_j)
                {
                    temp = num_i;
                    put_number_by_pos(num_j, i, f, &result);
                    put_number_by_pos(temp, j, f, &result);
                    if (result != OK)
                    {
                        fclose(f);
                        return result;
                    }
                }
            }
        fclose(f);
    }
    else
        result = ARGS_ERROR;
    return result;
}

int get_number_by_pos(int pos, FILE *f, int *result)
{
    int num;
    if (fseek(f, (long int) pos * sizeof(int), SEEK_SET) != 0)
        *result = FILE_ERROR;
    if (fread(&num, sizeof(int), 1, f) != 1)
        *result = FILE_ERROR;
    return num;
}

void put_number_by_pos(int number, int pos, FILE *f, int *result)
{
    if (fseek(f, (long int) pos * sizeof(int), SEEK_SET) != 0)
        *result = FILE_ERROR;
    if (fwrite(&number, sizeof(int), 1, f) != 1)
        *result = FILE_ERROR;
}