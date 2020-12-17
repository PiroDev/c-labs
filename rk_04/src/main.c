/* Реализовать универсальный односвязный список. Информационная основного часть списка – структура Student,
содержащая имя (char*), возраст (int), список оценок. Список оценок реализуется тем же списком, что список
студентов. Интерактивное меню. Реализовать функции:
- добавления элементов в конец
- удаления элементов с конца
- вывода элементов на экран */

#include "list_functions.h"
#include "input_output.h"
#include "student_io.h"

#include <stdio.h>

int main(void) {
    int cmd = -1;

    node_t *students_list = NULL;

    while (cmd)
    {
        printf("\n\n");
        print_commands();
        cmd = read_command();
        switch (cmd)
        {
            case 1:
                students_list = list_push_back(students_list, (void *) read_student(stdin));
                break;

            case 2:
                students_list = list_pop_back(students_list);
                break;

            case 3:
                print_list(students_list, print_student);
                break;

            case 0:
                break;

            default:
                printf("Неизвестная команда!\n");
                break;
        }
    }

    delete_list(students_list, delete_student);
}