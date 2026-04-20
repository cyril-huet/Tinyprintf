#include "convert.h"

#include "utils.h"

struct aux
{
    long long value;
    char *str;
    int index;
    const char *base;
    int base_len;
};

/* fill string with digits */
static void fill_base(struct aux *c, int exp)
{
    while (exp != -1)
    {
        long long div = my_pow(c->base_len, exp);
        int digit = c->value / div;

        c->value -= digit * div;
        c->str[c->index] = c->base[digit];

        exp--;
        c->index++;
    }
}

char *my_itoa_base(int n, char *s, const char *base)
{
    int base_len = 0;

    while (base[base_len] != '\0')
    {
        base_len++;
    }

    long long value = n;

    if (n < 0)
    {
        if (base_len == 10)
        {
            s[0] = '-';
            value = -n;
        }
        else
        {
            value = -n;
        }
    }

    if (value == 0)
    {
        s[0] = base[0];
        s[1] = '\0';
        return s;
    }

    int exp = 0;

    while (my_pow(base_len, exp) <= value && my_pow(base_len, exp) > 0)
    {
        exp++;
    }

    exp--;

    int index;

    if (n < 0 && base_len == 10)
    {
        index = 1;
    }
    else
    {
        index = 0;
    }

    struct aux c = { value, s, index, base, base_len };

    fill_base(&c, exp);

    s[c.index] = '\0';

    return s;
}
