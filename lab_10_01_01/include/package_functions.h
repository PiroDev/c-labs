#ifndef PACKAGE_FUNCTIONS_H_
#define PACKAGE_FUNCTIONS_H_

#include "list.h"
#include "package.h"

void install_packages(const node_t *list_head);
void install_package(const package_t *package);

int package_comparator(const void *, const void *);

#endif  // PACKAGE_FUNCTIONS_H_
