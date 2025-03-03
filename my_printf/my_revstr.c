/*
** EPITECH PROJECT, 2024
** task03
** File description:
** task03
*/

#include <stdio.h>
#include <unistd.h>

/*
** EPITECH PROJECT, 2024
** my_revstr.c
** File description:
** rev str
*/
#include "my.h"

void my_revstr(char *str, int i)
{
    char tmp;

    for (int j = 0; j < i / 2; j++) {
        tmp = str[j];
        str[j] = str[i - 1 - j];
        str[i - 1 - j] = tmp;
    }
    my_putstr(str);
}
