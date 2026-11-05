#include "relation_func.h"

int check_relation(FILE *f, double k1, double k2,double k3, double right)
{
    double first = 0., second = 0., third = 0.;
    double value = 0.;

    if (fscanf(f, "%lf", &first) != 1)

        return -1;

    if (fscanf(f, "%lf", &second) != 1)

        return -1;

    if (fscanf(f, "%lf", &third) != 1)

        return -1;

    while (1)

    {

        value = k1 * third + k2 * second + k3 * first;

        if (fabs(value - right) >= eps)

            return 0;

        first = second;

        second = third;

        if (fscanf(f, "%lf", &third) != 1)

            break;

    }

    return 1;

}
