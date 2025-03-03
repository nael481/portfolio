/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** miniprintf
*/
#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++);
    return i;
}
