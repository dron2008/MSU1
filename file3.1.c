#include <stdio.h>

int isNumberInFile(FILE *file, int X)
{
    int a;

    while (fscanf(file, "%d", &a) == 1)
    {
        if (a == X)
            return 1;
    }

    return 0;
}

int main()
{
    int X;

    printf("Введите X: ");
    scanf("%d", &X);

    FILE *file = fopen("input_data.txt", "r");

    if (file == NULL)
    {
        printf("Не удалось открыть файл\n");
        return 1;
    }

    if (isNumberInFile(file, X))
        printf("Число X есть в последовательности\n");
    else
        printf("Числа X нет в последовательности\n");

    fclose(file);

    return 0;
}
