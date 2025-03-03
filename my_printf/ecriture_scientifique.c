/*
** EPITECH PROJECT, 2024
** printf
** File description:
** %e
*/

#include "my.h"

int sup_10(double *nb)
{
    int exposant = 0;

    while (*nb >= 10) {
        *nb /= 10;
        exposant++;
    }
    return exposant;
}

int afficher_en_scientifique(double nb, int exposant)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    my_putdouble(nb);
    if (exposant >= 0) {
        my_putstr("e+");
    } else {
        my_putstr("e-");
        exposant = -exposant;
    }
    if (exposant < 10) {
        my_putchar('0');
    }
    my_putnbr(exposant);
    return 0;
}

int ecriture_scientifique(double nb)
{
    int exposant = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    exposant = convertir_exposant(&nb);
    return afficher_en_scientifique(nb, exposant);
}
