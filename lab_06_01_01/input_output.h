/**
 * \file input_output.h
 * \brief В этом файле находятся прототипы функций ввода-вывода и тип, описывающий коды состояния
*/
#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include <stdio.h>
#include <string.h>
#include "structs.h"

/**
 * \brief Максимально допустимый год выхода фильма на экран
*/
#define MAX_YEAR 9999

/**
 * \brief Минимально допустимый год выхода фильма на экран
*/
#define MIN_YEAR 1

/**
 * \brief Тип для кодов состояний
 * \param ok - ошибок нет
 * \param too_long_input_string - слишком длинное поле
 * \param wrong_arguments_count - неверное количество аргументов командной строки
 * \param wrong_arguments_value - неверное значение аргумента командной строки
 * \param file_input_error - ошибка при чтении из файла
 * \param empty_file_error - пустой файл
 * \param wrong_year_format - неверный формат года выхода фильма
 * \param too_many_structures - слишком много структур в файле
*/
typedef enum
{
    ok = 0,
    too_long_input_string = -1,
    wrong_arguments_count = -2,
    wrong_arguments_value = -3,
    file_input_error = -4,
    empty_file_error = -5,
    wrong_year_format = -6,
    too_many_structures = -7
} status_code;

/**
 * \brief Функция проверки аргументов командной строки
*/
status_code input_check(int, char **);

/**
 * \brief Функция для чтения структур из файла в массив
*/
status_code read_array(char *, film_array, int *);

/**
 * \brief Функция для чтения чисел одной структуры
*/
status_code read_film(FILE *, film_struct *);

/**
 * \brief Функция для чтения строки из файла
*/
status_code read_str(FILE *, char *, int);

/**
 * \brief Функция для перевода года в из строкового в числовой формат
*/
status_code string_year_to_int(char *, int *);

/**
 * \brief Функция для вывода массива структур на экран
*/
void print_array(film_array, int);

/**
 * \brief Функция для вывода одной структуры на экран
*/
void print_film(film_struct *);

#endif