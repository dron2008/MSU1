#include "sum_func.h"

int all_nums(FILE *f)
{
    double current = 0., previous = 0., b = 0.;
    int have_b = 0, count_a = 0, count_b = 0;

    if (fscanf(f, "%lf", &previous) != 1)
        return -1;

    count_a = 1;

    while (fscanf(f, "%lf", &current) == 1)
    {
        if (fabs(current - previous) < eps)
            count_a++;
        else if (have_b == 0)
        {
            b = current;
            have_b = 1;
            count_b = 1;
        }
        else if (fabs(current - b) < eps)
            count_b++;
        else
            return 0;
    }

    if (count_a > 1 && count_b > 1)
        return 0;

    return 1;
}
