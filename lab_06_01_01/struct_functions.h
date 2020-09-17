/**
 * \file struct_functions.h
 * \brief В этом файле находятся прототипы функций обработки стуктур и массивов структур
*/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "input_output.h"

/**
 * \brief Функция для сортировки массива структур по заданному полю
*/
void sort_array(film_array, int, char *);

/**
 * \brief Функция для сравнения двух структур по заданному полю
*/
int compare_films_by_field(char *, film_struct *, film_struct *);

/**
 * \brief Функция для бинарного поиска в массиве структур по заданному полю и значению ключа
*/
status_code binary_search(film_array, int, char *, char *, film_struct *);

/**
 * \brief Функция для обмена значений полей двух структур
*/
void swap(film_struct *, film_struct *);

/**
 * \brief Конструктор для структуры
*/
film_struct film_constructor(char *, char *);

#endif