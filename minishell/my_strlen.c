/*
** EPITECH PROJECT, 2024
** my_swap
** File description:
** day 4, task 1
** my_swap.c
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}
