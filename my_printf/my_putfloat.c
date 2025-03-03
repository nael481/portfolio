/*
** EPITECH PROJECT, 2024
** printf
** File description:
** %f
*/
#include "my.h"

int my_putfloat(float nb)
{
    my_putnbr((int) nb);
    my_putchar('.');
    nb -= (int)nb;
    nb *= 100000;
    my_putnbr((int)(nb));
    return 0;
}
