/*
** EPITECH PROJECT, 2024
** printf
** File description:
** je suis beau
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
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
    case 'o':
        octal(va_arg(ap, int));
        break;
    default:
        flag2(param, ap);
    }
}

void flag2(char param, va_list ap)
{
    switch (param){
    case 'x':
        hexa_min(va_arg(ap, int));
        break;
    case 'X':
        hexa_maj(va_arg(ap, int));
        break;
    case 'e':
        ecriture_scientifique(va_arg(ap, double));
        break;
    case 'E':
        maj_ecriture_scientifique(va_arg(ap, double));
        break;
    default:
        flag3(param, ap);
    }
}

void flag3(char param, va_list ap)
{
    switch (param){
    case 'f':
        my_putfloat(va_arg(ap, double));
        break;
    case 'p':
        modulo_p(va_arg(ap, int));
        break;
    default:
        break;
    }
}

int my_printf(const char *format, ...)
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
