#include <stdio.h>

int isNumberInfile(FILE *file, double X);
int isNumberInfile(FILE *file, double X)
{
int sum = 0;double a;
while (fscanf(file, "lf", &a) == 1)
if (a == X)
sum = sum + 1;
return sum;
}
int main (void)
{
double X; FILE *file;
printf ("Введите Х: ") ;
scanf ("lf", &X) ;
file = fopen ("input_data. txt", "r");
if (file == NULL)
{
printf ("Не удалось открыть файл\n") ;
return 1;
}
printf ("sd\n", isNumberInfile(file, X)) ;
close (file);
return 0;
}
