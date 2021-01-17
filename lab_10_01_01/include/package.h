#ifndef PACKAGE_H_
#define PACKAGE_H_

typedef struct
{
    char *name;
    int version;
} package_t;

package_t *new_package(void);
void delete_package(package_t *package);

#endif  // PACKAGE_H_
