#define _GNU_SOURCE

#include "../include/package_io.h"

#include <stdlib.h>
#include <string.h>

#include "../include/list_functions.h"

void remove_newline_symbol_from_str(char *str)
{
    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
}

status_code_t validate_args(int argc, char **argv)
{
    status_code_t result = ok;

    if (argc == 3)
    {
        if (strcmp(argv[1], "install"))
            result = error_unknown_args;
    }
    else if (argc == 4)
    {
        if (strcmp(argv[1], "sort"))
            result = error_unknown_args;
    }
    else
        result = error_wrong_args_count;

    return result;
}

status_code_t read_packages_from_file(const char *fname, node_t **list_head)
{
    status_code_t result = ok;

    FILE *f = fopen(fname, "r");
    if (f)
    {
        while (!feof(f) && !result)
        {
            package_t *package = new_package();
            result = read_package(f, package);
            if (!result)
                *list_head = push_front(*list_head, package);
        }
        fclose(f);
    }
    else
        result = error_while_open_input_file;

    return result;
}

status_code_t read_package(FILE *f, package_t *package)
{
    status_code_t result = ok;

    ssize_t count = 0;
    size_t n = 0;
    if ((count = getline(&(package->name), &n, f)) != -1)
    {
        remove_newline_symbol_from_str(package->name);
        if (fscanf(f, "%d", &package->version) != 1 || package->version <= 0)
            result = error_wrong_value_in_file;
        fscanf(f, "%*[\n]");
    }
    else
        result = error_wrong_value_in_file;
    if (result)
        free(package->name);

    return result;
}

status_code_t print_packages_to_file(const char *fname, const node_t *list_head)
{
    status_code_t result = ok;

    FILE *f = fopen(fname, "w");
    if (f)
    {
        while (list_head)
        {
            print_package(f, (package_t *)list_head->data);
            list_head = list_head->next;
        }
        fclose(f);
    }
    else
        result = error_while_open_output_file;

    return result;
}

void print_package(FILE *f, const package_t *package)
{
    fprintf(f, "%s\n%d\n", package->name, package->version);
}
