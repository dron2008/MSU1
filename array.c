
#include "array.h"
#include <stdio.h>
#include <stdlib.h>

int main_program(void)
{
    FILE *f;
    int n = 0;
    int x;
    int *arr;
    int i;
    int min;
    int predmin;
    int found = 0;
    int last = -1;

    f = fopen("input_data.txt", "r");

    if (f == NULL)
    {
        printf("Нет файла\n");
        return 1;
    }

    while (fscanf(f, "%d", &x) == 1)
    {
        n++;
    }

    if (n == 0)
    {
        printf("Файл пуст\n");
        fclose(f);
        return 1;
    }
    arr = malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Нет памяти\n");
        fclose(f);
        return 1;
    }
    rewind(f);

    for (i = 0; i < n; i++)
    {
        if (fscanf(f, "%d", &arr[i]) != 1)
        {
            printf("Ошибка чтения\n");
            free(arr);
            fclose(f);
            return 1;
        }
    }

    fclose(f);

    min = arr[0];

    for (i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i] > min)
        {
            if (found == 0 || arr[i] < predmin)
            {
                predmin = arr[i];
                found = 1;
            }
        }
    }

    if (found == 0)
    {
        printf("Нет предминимума\n");
        free(arr);
        return 1;
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i] == predmin)
        {
            last = i;
        }
    }

    printf("Последний номер: %d\n", last + 1);

    free(arr);

    return 0;
}
