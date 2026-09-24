int sum = 0;

int isNumberInFile(FILE *file, int X)
{
    int a;

    while (fscanf(file, "%d", &a) == 1)
    {
        if (a == X)
        {
            sum = sum + 1;
        }
    }

    return sum;
}

int main(void)
{
    int X;
    FILE *file;

    printf("Введите X: ");
    scanf("%d", &X);

    file = fopen("input_data.txt", "r");

    if (file == NULL)
    {
        printf("Не удалось открыть файл\n");
        return 1;
    }

    printf("%d\n", isNumberInFile(file, X));

    fclose(file);

    return 0;
}
