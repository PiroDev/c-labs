#include <string.h>
#include "functions.h"

#define MAX_STRUCTS_COUNT 100

status_code process(int argc, char **argv)
{
    status_code result = ok;
    if ((argc == 4) && (strcmp((const char *) argv[1], "st") == 0))
        result = sort_text_file(argv[2], argv[3]);
    else if ((argc == 4) && (strcmp((const char *) argv[1], "ft") == 0))
        result = find_in_text_file(argv[2], argv[3]);
    else if ((argc == 3) && (strcmp((const char *) argv[1], "at") == 0))
        result = add_in_text_file(argv[2]);
    else
        result = unknown_args_error;
    return result;
}

status_code sort_text_file(char *fname_in, char *fname_out)
{
    status_code result = ok;
    FILE *f_in = NULL;
    FILE *f_out = NULL;
    f_in = fopen((const char *) fname_in, "r");
    f_out = fopen((const char *) fname_out, "w");
    if ((f_in != NULL) && (f_out != NULL))
    {
        product items[MAX_STRUCTS_COUNT];
        product item = read_item(f_in, &result);
        int n = 0;
        while (result == ok)
        {
            items[n] = item;
            item = read_item(f_in, &result);
            n++;
        }
        if ((n != 0) && (feof(f_in)))
        {
            result = ok;
            for (int i = 0; i < n - 1; i++)
                for (int j = i + 1; j < n; j++)
                    if (products_compare(items[i], items[j]) < 0)
                    {
                        product buf = items[i];
                        items[i] = items[j];
                        items[j] = buf;
                    }
            for (int i = 0; i < n; i++)
                write_item(f_out, items[i]);
        }
        else if (n == 0)
            result = file_error;
        else
            result = input_error;
    }
    else
        result = unknown_args_error;
    FILE *files[2] = { f_in, f_out };
    close_files(files, 2);
    return result;
}

status_code find_in_text_file(char *fname, char *key)
{
    status_code result = ok;
    FILE *f = NULL;
    f = fopen((const char *) fname, "r");
    if (f != NULL)
    {
        product item;
        int n = 0;
        while (result == ok)
        {
            item = read_item(f, &result);
            if (result == ok)
            {
                if (ends_with(item.name, key) > 0)
                {
                    n++;
                    write_item(stdout, item);
                }
            }
        }
        if ((n != 0) && feof(f))
            result = ok;
        else if (n == 0)
            result = file_error;
        else
            result = input_error;
        fclose(f);
    }
    else
        result = args_error;
    return result;
}

status_code add_in_text_file(char *fname)
{
    status_code result = ok;
    FILE *f = NULL;
    f = fopen(fname, "r+");
    if (f != NULL)
    {
        product item = read_item(stdin, &result);
        if (result == ok)
        {
            product items[MAX_STRUCTS_COUNT];
            int index = 0;
            product curr_item;
            int flag = 1;
            while (flag)
            {
                curr_item = read_item(f, &result);
                if ((result == ok) && (products_compare(curr_item, item) > 0))
                    items[index++] = curr_item;
                else
                    flag = 0;
            }
            items[index++] = item;
            if (result == ok)
                items[index++] = curr_item;
            while (result == ok)
            {
                curr_item = read_item(f, &result);
                if (result == ok)
                    items[index++] = curr_item;
            }
            result = ok;
            fseek(f, 0, SEEK_SET);
            for (int i = 0; i < index; i++)
                write_item(f, items[i]);
        }
        else
            result = input_error;
        fclose(f);
    }
    else
        result = unknown_args_error;
    return result;
}

product read_item(FILE *f, status_code *result)
{
    product item = { .price = 0 };
    *result = ok;
    if (fscanf(f, "%s%s%d%d", item.name, item.company, &(item.price), &(item.count)) != 4)
        *result = input_error;
    return item;
}

status_code write_item(FILE *f, product item)
{
    status_code result = ok;
    if (fprintf(f, "%s\n%s\n%d\n%d\n", item.name, item.company, item.price, item.count) != 4)
        result = file_error;
    return result;
}

int products_compare(product item_1, product item_2)
{
    if (item_1.price > item_2.price)
        return 1;
    else if (item_1.price == item_2.price)
    {
        if (item_1.count > item_2.count)
            return 1;
        else if (item_1.count == item_2.count)
            return 0;
        else
            return -1;
    }
    else
        return -1;
}

int ends_with(char *str, char *substr)
{
    int result = -1;
    int len_1 = strlen(str);
    int len_2 = strlen(substr);
    if (len_1 >= len_2)
    {
        int i = 0;
        while ((i < len_2) && (str[len_1 - i - 1] == substr[len_2 - i - 1]))
            i++;
        if (i == len_2)
            result = 1;
    }
    return result;
}

void close_files(FILE **files, int count)
{
    for (int i = 0; i < count; i++)
        if (files[i] != NULL)
            fclose(files[i]);
}