#include "input_output.h"
#include "student.h"

#include <stdio.h>

void print_list(node_t *head, void (*print_data)(void *data))
{
    while (head)
    {
        print_data(head->data);
        printf(" -> ");
        head = head->next;
    }
    printf("NULL");
}

void print_commands(void)
{
    printf(
        "Доступные команды:\n"
        "1 - Добавить студента в список\n"
        "2 - Удалить последнего студента в списке\n"
        "3 - Рапечатать список\n"
        "0 - Выйти из программы\n\n"
    );
}

int read_command(void)
{
    int cmd = -1;

    printf("Введите команду: ");
    if (scanf("%d", &cmd) != 1)
        cmd = -1;

    return cmd;
}
