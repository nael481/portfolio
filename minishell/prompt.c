/*
** EPITECH PROJECT, 2025
** shell1
** File description:
** shell1
*/

#include "my.h"

void prompt(void)
{
    char *path = getcwd(NULL, 0);

    my_putstr("\x1b[1m\x1b[32m $> \x1b[0m");
    my_putstr("\x1b[1m\x1b[34m");
    my_putstr(path);
    my_putstr("\x1b[0m ");
    free(path);
    return;
}
