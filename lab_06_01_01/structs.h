#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX_TITLE_LENGTH 25
#define MAX_SURNAME_LENGTH 25
#define MAX_STRUCTS_COUNT 15
#define MAX_YEAR_LENGTH 4

typedef struct
{
    char title[MAX_TITLE_LENGTH + 1];
    char surname[MAX_SURNAME_LENGTH + 1];
    int year;
} film_struct;

typedef film_struct film_array[MAX_STRUCTS_COUNT];

#endif