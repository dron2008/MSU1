#include "sum_func.h"

int main(void)
{
    FILE *f = fopen("input_data.txt", "r");

    if (f == NULL)
    {
        printf("File error\n");
        return -1;
    }

    int result = all_nums(f);

    fclose(f);

    if (result == -1)
        printf("File is empty\n");
    else if (result == 1)
        printf("Все или кроме одного равны\n");
    else
        printf("Не все или кроме одного равны\n");

    return 0;
}
