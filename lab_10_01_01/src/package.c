#include "../include/package.h"

#include <stdlib.h>

package_t *new_package(void)
{
    package_t* package = malloc(sizeof(package_t));
    if (package)
    {
        package->name = NULL;
        package->version = 0;
    }
    return package;
}

void delete_package(package_t *package)
{
    free(package->name);
    free(package);
}
