#include "relation_func.h"

int main(void)
{
FILE *f;
double k1 = 0., k2 = 0., k3 = 0., right = 0.;
int result = 0;

printf("Введите k1, k2, k3 и b:\n");

if (scanf("%lf %lf %lf %lf", &k1, &k2, &k3, &right) != 4)
{
printf("Input error\n");
return -1;
}

f = fopen("input_data.txt", "r");

if (f == NULL)
{
printf("File error\n");
return -1;
}

result = check_relation(f, k1, k2, k3, right);

fclose(f);

if (result == -1)
printf("Недостаточно элементов в файле\n");
else if (result == 1)
printf("Соотношение выполняется\n");
else
printf("Соотношение не выполняется\n");

return 0;
}
