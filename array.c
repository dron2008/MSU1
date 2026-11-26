#include "array.h"

int predmintions(FILE *f)
{
    int len, int i;int flag, int last, double *arr, double min, double predmin,flag = 0, last = -1;

    if (fscanf(f, "%d", &len) != 1)
    {
        return -2;
    }

    if (len <= 0)
    {
        return -2;
    }

    arr = (double *)malloc(len * sizeof(double));

    if (arr == NULL)
    {
        return -2;
    }

    for (i = 0; i < len; i++)
    {
        if (fscanf(f, "%lf", &arr[i]) != 1)
        {
            free(arr);
            return -2;
        }
    }

    min = arr[0];

    for (i = 1; i < len; i++)
    {
        if (arr[i] < min - eps)
        {
            min = arr[i];
        }
    }

    for (i = 0; i < len; i++)
    {
        if (arr[i] > min + eps)
        {
            if (flag == 0)
            {
                predmin = arr[i];
                last = i;
                flag = 1;
            }
            else if (arr[i] < predmin - eps)
            {
                predmin = arr[i];
                last = i;
            }
            else if (fabs(arr[i] - predmin) < eps)
            {
                last = i;
            }
        }
    }

    free(arr);

    if (flag == 0)
    {
        return -1;
    }

    return last + 1;
}
