/**
 * \file functions.h
 * \brief В этом файле находятся прототипы функций для работы с массивами и другие полезные функции
*/
#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <stddef.h>

/**
 * \brief Функция для освобождения памяти и обнуления указателей
*/
void free_resources(int **, int **);

/**
 * \brief Универсальная функция сортировки (модифицированный метод пузырька)
*/
void mysort(void *, int, size_t, int (*)(const void *, const void *));

/**
 * \brief Функция-фильтр
*/
int key(const int *, const int *, int **, int **);

/**
 * \brief Функция сравнения двух int
*/
int cmp_int(const void *, const void *);

/**
 * \brief Универсальная функция обмена значениями
*/
void swap(void *, void *, size_t);

/**
 * \brief Функция проверки числа на четность
*/
int is_even(int);

/**
 * \brief Функция копирования count первых элементов массива в другой массив
*/
void copy_array(const int *, int *, int);

#endif