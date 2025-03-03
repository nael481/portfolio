/*
** EPITECH PROJECT, 2024
** mini printf
** File description:
** je suis beau
*/


#include "my.h"

void flag(const char *param, int i, va_list ap)
{
    switch (param[i]) {
    case 'd':
        my_putnbr(va_arg(ap, int));
        break;
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
        my_putchar(param[i]);
    }
}

int mini_printf(const char *param, ...)
{
    int i = 0;
    va_list ap;

    va_start(ap, param);
    for (i = 0; param[i] != '\0'; i++) {
        if (param[i] == '%') {
            i++;
            flag(param, i, ap);
        } else {
            my_putchar(param[i]);
        }
    }
    va_end(ap);
    return 0;
}
