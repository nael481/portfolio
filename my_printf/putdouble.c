/*
** EPITECH PROJECT, 2024
** putdoubl
** File description:
** printf
*/
#include "my.h"

int my_putdouble(double nb)
{
    my_putnbr((int) nb);
    my_putchar('.');
    nb -= (int)nb;
    nb *= 1000000;
    my_putnbr((int)(nb));
    return 0;
}
