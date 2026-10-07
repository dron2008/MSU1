#include "sum_func.h"

int all_equal(FILE *f)
{
    double current = 0., previous = 0.;

    if (fscanf(f, "%lf", &previous) != 1)
    {
        printf("File is empty");
        return 1;
    }

    while (fscanf(f, "%lf", &current) == 1)
    {
        if (fabs(current - previous) >= eps)
            return 0;

        previous = current;
    }

    return 1;
}
