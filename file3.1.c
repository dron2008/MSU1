#include <stdio.h>

int isNumberInFile(FILE *file, int X);
int sum = 0;
int isNumberInFile(FILE *fi-le, int X)
{
int sum = 0;int a;
while (fscanf(file, "ed", &a) == 1)
if (a == X)
sum = sum + 1;
return sum;
int main (void)
int X; FILE *file;
printf ("Введите Х: ") ;
scanf ("d", &X) ;
file = fopen ("input_data. txt", "r");
if (file == NULL)
{
printf ("Не удалось открыть файл\n") ;
return 1;
printf ("sd\n", isNumberInfile(file, X)) ;
close (file);
return 0;
