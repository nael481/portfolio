/*
** EPITECH PROJECT, 2024
** my_putchar
** File description:
** miniprintf
*/

#include "my.h"

int my_putchar(char character)
{
    write(1, &character, sizeof(character));
    return character;
}
