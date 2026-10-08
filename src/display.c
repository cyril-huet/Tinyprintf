#include "display.h"

#include <stdio.h>
#include <stdlib.h>

#include "convert.h"
#include "utils.h"

/* signed int */
int displaysigneddecimal(int n)
{
    int count = 0;
    long long size = calcul(n, 10);

    if (n < 0)
    {
        size++;
    }

    char *s = malloc(size + 1);

    my_itoa_base(n, s, "0123456789");

    int i = 0;

    while (s[i] != '\0')
    {
        putchar(s[i]);
        i++;
        count++;
    }

    free(s);

    return count;
}

/* unsigned */
int displayunsigneddecimal(unsigned int n)
{
    int count = 0;
    long long size = calcul(n, 10);

    char *s = malloc(size + 1);

    my_itoa_base(n, s, "0123456789");

    int i = 0;

    while (s[i] != '\0')
    {
        putchar(s[i]);
        i++;
        count++;
    }

    free(s);

    return count;
}

/* string */
int displaystring(char *s)
{
    if (s == NULL)
    {
        s = "(null)";
    }

    int count = 0;
    int i = 0;

    while (s[i] != '\0')
    {
        putchar(s[i]);
        i++;
        count++;
    }

    return count;
}

/* hex */
int displayhexa(int x)
{
    int count = 0;
    long long size = calcul(x, 16);

    char *s = malloc(size + 1);

    my_itoa_base(x, s, "0123456789abcdef");

    int i = 0;

    while (s[i] != '\0')
    {
        putchar(s[i]);
        i++;
        count++;
    }

    free(s);

    return count;
}

/* octal */
int displayoctal(long long o)
{
    int count = 0;
    long long size = calcul(o, 8);

    char *s = malloc(size + 1);

    my_itoa_base(o, s, "01234567");

    int i = 0;

    while (s[i] != '\0')
    {
        putchar(s[i]);
        i++;
        count++;
    }

    free(s);

    return count;
}
