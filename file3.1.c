#include <stdio.h> 
#define eps 1.e-10
#include <math.h>
int isNumberInfile(FILE *file, double X);
int isNumberInfile(FILE *file, double X)
{
    int sum = 0;
    double a;
while (fscanf(file, "%lf", &a) == 1)
        if (fabs(a - X) < eps) sum++;
return sum;
}
int main(void)
{
    double X; FILE *file;
    printf("Введите X: ");
    scanf("%lf", &X);
    file = fopen("input_data.txt", "r");
    if (file == NULL)
    {
        printf("Не удалось открыть файл\n");
        return 1;
    }

    printf("%d\n", isNumberInfile(file, X));
    fclose(file);
    return 0;
}
