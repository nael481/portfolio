/*
** EPITECH PROJECT, 2025
** printf
** File description:
** printf
*/

#include "my.h"

int my_long_putnbr(long n)
{
    if (n < 0) {
        my_putchar('-');
        n = -n;
    }
    if (n / 10 > 0)
        my_putnbr(n / 10);
    my_putchar((n % 10) + '0');
}
