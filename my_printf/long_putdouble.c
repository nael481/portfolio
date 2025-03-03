/*
** EPITECH PROJECT, 2024
** putdoubl
** File description:
** printf
*/
#include "my.h"

int long_my_putdouble(long nb)
{
    my_putnbr((long) nb);
    my_putchar('.');
    nb -= (long)nb;
    nb *= 1000000;
    my_putnbr((long)(nb));
    return 0;
}
