#include "tinyprintf.h"

#include <stdarg.h>
#include <stdio.h>

#include "display.h"

int tinyprintf(const char *format, ...)
{
    va_list args;
    int i = 0;
    int res = 0;

    va_start(args, format);

    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            if (format[i + 1] != '\0')
            {
                if (format[i + 1] == 'd')
                    res += displaysigneddecimal(va_arg(args, int));
                else if (format[i + 1] == 'u')
                    res += displayunsigneddecimal(va_arg(args, unsigned int));
                else if (format[i + 1] == 'c')
                {
                    putchar(va_arg(args, int));
                    res++;
                }
                else if (format[i + 1] == 's')
                    res += displaystring(va_arg(args, char *));
                else if (format[i + 1] == 'x')
                    res += displayhexa(va_arg(args, long long));
                else if (format[i + 1] == 'o')
                    res += displayoctal(va_arg(args, long long));
                else if (format[i + 1] == '%')
                    res += putchar('%');
                else
                {
                    putchar('%');
                    putchar(format[i + 1]);
                    res += 2;
                }
                i++;
            }
        }
        else
        {
            putchar(format[i]);
            res++;
        }
        i++;
    }

    va_end(args);

    return res;
}
