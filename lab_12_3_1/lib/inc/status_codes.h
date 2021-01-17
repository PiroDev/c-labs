/**
 * \file status_codes.h
 * \brief В этом файле находится тип данных, описывающий коды состояния программы
*/
#ifndef __STATUS_CODES_H__
#define __STATUS_CODES_H__

/**
 * \brief Тип для кодов состояния
 * \param ok - ошибок нет
 * \param error_wrong_number_of_args - неверное количество аргументов командной строки
 * \param error_wrong_command_line_args - неверные аргументы командной строки
 * \param error_cannot_open_input_file - не получается открыть входной файл
 * \param error_wrong_value_in_file - не получается считать значения из файла
 * \param error_empty_input_file - пустой входной файл
 * \param error_cannot_open_output_file - не получается создать (открыть на запись) выходной файл
 * \param error_empty_filtration_output - последовательность после фильтрации оказалась пустой
 * \param error_out_of_memory - ошибка при выделении памяти
*/
typedef enum
{
    ok = 0,
    error_wrong_number_of_args = -1,
    error_wrong_command_line_args = -2,
    error_cannot_open_input_file = -3,
    error_wrong_value_in_file = -4,
    error_empty_input_file = -5,
    error_cannot_open_output_file = -6,
    error_empty_filtration_output = -7,
    error_out_of_memory = -8,
    error_null_ptr = -9,
    error_open_lib = -10
} status_code;

#endif