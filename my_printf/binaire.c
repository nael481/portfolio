/*
** EPITECH PROJECT, 2024
** binaire
** File description:
** my_printf.c
*/

#include <stdio.h>

void decimal(int n)
{
    int binaire[32];
    int i = 0;

    while (n > 0) {
        binaire[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        my_putnbr("%d", binaire[j]);
}
