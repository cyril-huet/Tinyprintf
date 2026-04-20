#include "utils.h"

/* power */
long long my_pow(long long a, long long b)
{
    long long res = 1;
    long long i = 0;

    while (i < b)
    {
        res *= a;
        i++;
    }

    return res;
}

/* count digits in base */
long long calcul(long long n, int base)
{
    long long res = 0;

    if (n == 0)
    {
        return 1;
    }

    while (n != 0)
    {
        n = n / base;
        res++;
    }

    return res;
}
