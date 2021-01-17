#ifndef PACKAGE_IO_H_
#define PACKAGE_IO_H_

#include <stdio.h>

#include "list.h"
#include "package.h"
#include "status_codes.h"

status_code_t validate_args(int argc, char **argv);
status_code_t read_packages_from_file(const char *fname, node_t **list_head);
status_code_t read_package(FILE *f, package_t *package);
status_code_t print_packages_to_file(const char *fname, const node_t *list_head);
void print_package(FILE *f, const package_t *package);

#endif  // PACKAGE_IO_H_
