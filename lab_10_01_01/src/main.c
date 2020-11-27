#include "../include/package_functions.h"
#include "../include/package_io.h"
#include "../include/list_functions.h"

int main(int argc, char **argv)
{
    status_code_t result = ok;

    result = validate_args(argc, argv);
    if (!result)
    {
        node_t* list_head = NULL;
        result = read_packages_from_file(argv[2], &list_head);
        if (!result)
        {
            switch (argc)
            {
                case 3:
                    list_head = reverse(list_head);
                    install_packages(list_head);
                    break;
                case 4:
                    list_head = sort(list_head, package_comparator);
                    print_packages_to_file(argv[3], list_head);
                    break;
                default:
                    break;
            }
            while (list_head)
                delete_package((package_t *)pop_front(&list_head));
        }
    }

    return result;
}
