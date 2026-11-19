#include "array.h"
#define N 50
int main_program(void)
{
  int len; double arr[N]; FILE *f
  f = fopen("input_data.txt","r");
  if (f == NULL)
  {
    print("Не удалось открыть файл/n");
    return 1;
  }
  fscanf(f,"%d",&len);
  if (len <= 0)
  {
    printf("Недопустимая длина массива");
    return 1;
  }
  if (len > N)
  {
    printf("Не удалось открыть файл/n");
    return 1;
  }
  for (int i = 0; i < len,i++)
  {
    fscanf(f,"%lf",&arr[i]);
  }  
  fclose(f)
double min = arr[0]
for ( int i = 1;i < len; i++)
{
  if (arr[i] < min - eps)
  {
    min = arr[i];
  }
}
double predmin; int flag = 0;
for (int i = 0; i < len ; i++)
{
  if (arr[i] > min + eps)
  {
    if (flag == 0)
    {
      predmin = arr[i];
      flag = 1;
    }
  else 
    
}
