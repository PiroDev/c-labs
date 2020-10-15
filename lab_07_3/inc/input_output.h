/**
 * \file input_output.h
 * \brief В этом файле находятся прототипы функций ввода-вывода
*/
#ifndef __INPUT_OUTPUT_H__
#define __INPUT_OUTPUT_H__

#include <stdio.h>
#include "status_codes.h"

#define FILTRATION_MARKER "f"

/**
 * \brief Функция для считывания целых чисел из входного файла в массив и получения указателя на элемент за последним в массиве
*/
status_code input_from_text_file(char *, int **, int **);

/**
 * \brief Функция для записи массива целых чисел в выходной файл
*/
status_code output_in_text_file(char *, int *, int *);

#endif