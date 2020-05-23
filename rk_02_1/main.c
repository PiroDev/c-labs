#include <stdio.h>
#define MAXLEN_TOWN_NAME 100
#define MAX_STRUCTS_COUNT 1300
#define TOWNS_MAX_COUNT 5

typedef enum
{
    ok = 0,
    file_error = -1,
    input_error = -2
} status_code;

typedef struct
{
    char name[MAXLEN_TOWN_NAME + 1];
    int foundation_date;
    long int population;
} town;

status_code process(FILE *, FILE *);
status_code input(FILE *, town *, int *);
status_code read_item(FILE *, town);
void print(FILE *, town *);
status_code read_str(FILE *, char *, int);

int main()
{
    status_code result = ok;
    FILE *f_in = fopen("in.txt", "r");
    FILE *f_out = fopen("out.txt", "w");
    result = process(f_in, f_out);
    return result;
}

status_code process(FILE *f_in, FILE *f_out)
{
    status_code result = ok;
    if ((f_in != NULL) && (f_out != NULL))
    {
        town towns[MAX_STRUCTS_COUNT];
        int count = 0;
        result = input(f_in, towns, &count);
        if (result == ok)
        {
            town item = { { '\0' }, 0, 0 };
            town max_towns[TOWNS_MAX_COUNT];
            max_towns[0] = item;
            for (int i = 0; i < count; i++)
            {
                if (towns[i].population > max_towns[0].population)
                {
                    max_towns[4] = max_towns[3];
                    max_towns[3] = max_towns[2];
                    max_towns[2] = max_towns[1];
                    max_towns[1] = max_towns[0];
                    max_towns[0] = towns[i];
                }
                if (towns[i].population > max_towns[1].population)
                {
                    max_towns[4] = max_towns[3];
                    max_towns[3] = max_towns[2];
                    max_towns[2] = max_towns[1];
                    max_towns[1] = towns[i];
                }
                if (towns[i].population > max_towns[2].population)
                {
                    max_towns[4] = max_towns[3];
                    max_towns[3] = max_towns[2];
                    max_towns[2] = towns[i];
                }
                if (towns[i].population > max_towns[3].population)
                {
                    max_towns[4] = max_towns[3];
                    max_towns[3] = towns[i];
                }
                if (towns[i].population > max_towns[4].population)
                {
                    max_towns[4] = towns[i];
                }
            }
            print(stdout, towns);
            print(f_out, max_towns);
        }
    }
    else
        result = file_error;
    return result;
}

status_code input(FILE *f, town towns[], int *count)
{
    status_code result = ok;
    town item = { { '\0' }, 0, 0};
    int i = 0;
    while (!(feof(f)) && (i < MAX_STRUCTS_COUNT))
    {
        if ((result = read_item(f, item)) == ok)
            towns[i] = item;
        else
            break;
        i++;
    }
    *count = i;
    if (i < 5)
        result = input_error;
    return result;
}

status_code read_item(FILE *f, town item)
{
    status_code result = ok;
    if ((read_str(f, item.name, MAXLEN_TOWN_NAME) != ok) || (fscanf(f, "%d%ld", &(item.foundation_date), &(item.population)) != 2))
    {
        if (feof(f))
            result = input_error;
        else
            result = ok;
    }
    else
        fgetc(f);
    printf("%s\n", item.name);
}

status_code read_str(FILE *f, char *str, int max_count)
{
    status_code result = ok;
    int count = 0;
    char c = 0;
    while ((count < max_count) && ((c = fgetc(f)) != EOF) && (c != '\n'))
    {
        str[count] = c;
        count++;
    }
    if ((c != '\n') && (c != EOF))
        result = input_error;
    return result;
}

void print(FILE *f, town towns[])
{
    for (int i = 0; i < TOWNS_MAX_COUNT; i++)
        fprintf(f, "%s\n", towns[i].name);
}

