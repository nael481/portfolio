/*
** EPITECH PROJECT, 2024
** printf
** File description:
** %E
*/
#include "my.h"

int convertir_exposant(double *nb)
{
    int exposant = 0;

    if (*nb < 0) {
        *nb = -* nb;
    }
    if (*nb >= 1) {
        exposant = sup_10(nb);
    }
    if (*nb > 0 && *nb < 1) {
        while (*nb < 1) {
            *nb *= 10;
            exposant--;
        }
    }
    return exposant;
}

int afficher_en_scientifique_maj(double nb, int exposant)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    my_putdouble(nb);
    if (exposant >= 0) {
        my_putstr("E+");
    } else {
        my_putstr("E-");
        exposant = -exposant;
    }
    if (exposant < 10) {
        my_putchar('0');
    }
    my_putnbr(exposant);
    return 0;
}

int maj_ecriture_scientifique(double nb)
{
    int exposant = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    exposant = convertir_exposant(&nb);
    return afficher_en_scientifique(nb, exposant);
}
