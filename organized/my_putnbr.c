/*
** EPITECH PROJECT, 2024
** my_putnbr
** File description:
** miniptintf
*/

#include "my.h"

int my_putnbr(int n)
{
    if (n < 0) {
        my_putchar('-');
        n = -n;
    }
    if (n / 10 > 0)
        my_putnbr(n / 10);
    my_putchar((n % 10) + '0');
}
