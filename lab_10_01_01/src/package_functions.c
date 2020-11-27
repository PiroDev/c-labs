#include "package_functions.h"

#include <stdio.h>
#include <string.h>

#include "list_functions.h"

void install_packages(const node_t *list_head)
{
    while (list_head)
    {
        package_t *package = (package_t *)list_head->data;
        install_package(package);
        list_head = list_head->next;
    }
}

void install_package(const package_t *package)
{
    printf("install %s v%d\n", package->name, package->version);
}

int package_comparator(const void *package_first, const void *package_second)
{
    int result = strcmp(((package_t *)package_second)->name, ((package_t *)package_first)->name);
    if (!result)
        result = ((package_t *)package_first)->version - ((package_t *)package_second)->version;
    return result;
}
