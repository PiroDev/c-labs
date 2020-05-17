#include "functions.h"

int main(int argc, char **argv)
{
    status_code result = ok;
    result = process(argc, argv);
    return result;
}