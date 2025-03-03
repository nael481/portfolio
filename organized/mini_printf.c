/*
** EPITECH PROJECT, 2024
** mini printf
** File description:
** je suis beau
*/

#include <stdarg.h>
#include <unistd.h>
#include "my.h"

void flag(char param, va_list ap)
{
    switch (param) {
    case 'd':
    case 'i':
        my_putnbr(va_arg(ap, int));
        break;
    case 's':
        my_putstr(va_arg(ap, char *));
        break;
    case 'c':
        my_putchar(va_arg(ap, int));
        break;
    case '%':
        my_putchar('%');
        break;
    default:
        break;
    }
}

int mini_printf(const char *format, ...)
{
    int i = 0;
    va_list ap;

    va_start(ap, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            i++;
            flag(format[i], ap);
        } else {
            my_putchar(format[i]);
        }
        i++;
    }
    va_end(ap);
    return 0;
}
