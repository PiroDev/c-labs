#ifndef MY_STDIO_H_
#define MY_STDIO_H_

#define MAX_OCT_LEN 100

#include <stddef.h>  // size_t

int my_snprintf(char *buf, size_t buf_size, const char *format, ...);

#endif  // MY_STDIO_H_
