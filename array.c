
#include "array.h"

int predmintions(FILE *f)
{
    int len;
    double arr[N];

    if (fscanf(f, "%d", &len) != 1)
    {
        return -2;
    }

    if (len <= 0)
    {
        return -2;
    }

    if (len > N)
    {
        return -2;
    }

    for (int i = 0; i < len; i++)
    {
        if (fscanf(f, "%lf", &arr[i]) != 1)
        {
            return -2;
        }
    }

    double min = arr[0];

    for (int i = 1; i < len; i++)
    {
        if (arr[i] < min - eps)
        {
            min = arr[i];
        }
    }

    double predmin;
    int flag = 0;

    for (int i = 0; i < len; i++)
    {
        if (arr[i] > min + eps)
        {
            if (flag == 0)
            {
                predmin = arr[i];
                flag = 1;
            }
            else
            {
                if (arr[i] < predmin - eps)
                {
                    predmin = arr[i];
                }
            }
        }
    }

    if (flag == 0)
    {
        return -1;
    }

    int last = -1;

    for (int i = 0; i < len; i++)
    {
        if (fabs(arr[i] - predmin) < eps)
        {
            last = i;
        }
    }

    return last + 1;
}
