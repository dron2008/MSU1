#include <math.h>
#include "sum_func.h"

int main(void)
{
    FILE *f = fopen("input_data.txt", "r");

    if (f == NULL)
    {
        printf("File error");
        return -1;
    }
    else
    {
        int result = all_equal(f);

        if (result == 1)
            printf("All elements are equal\n");
        else
            printf("Not all elements are equal\n");

        fclose(f);

        return 0;
    }
}
