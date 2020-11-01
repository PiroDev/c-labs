/**
 * \file structs.h
 * \brief В этом файле находится структура для хранения информации о фильме и ограничения на размер её полей
*/
#ifndef STRUCTS_H
#define STRUCTS_H

/**
 * \brief Максимально допустимая длина названия фильма
*/
#define MAX_TITLE_LENGTH 25

/**
 * \brief Максимально допустимая длина фамилии режиссера
*/
#define MAX_SURNAME_LENGTH 25

/**
 * \brief Максимально допустимое структур в файле
*/
#define MAX_STRUCTS_COUNT 15

/**
 * \brief Максимально допустимое количество цифр в записи года
*/
#define MAX_YEAR_LENGTH 4

/**
 * \brief Структура для хранения информации о фильме
 * \param title - название фильма
 * \param surname - фамилия режиссера
 * \param year - год выхода фильма на экран
*/
typedef struct
{
    char title[MAX_TITLE_LENGTH + 1];
    char surname[MAX_SURNAME_LENGTH + 1];
    int year;
} film_struct;

/**
 * \brief Тип массива структур
*/
typedef film_struct film_array[MAX_STRUCTS_COUNT];

#endif