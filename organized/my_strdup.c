/*
** EPITECH PROJECT, 2024
** organized
** File description:
** strdup
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(const char *str)
{
    int len = my_strlen(str);
    char *new_str;

    new_str = malloc(len + 1);
    if (new_str == NULL) {
        write(2, "Memory allocation failed.\n", 25);
        exit(84);
    }
    for (int i = 0; i < len; i++) {
        new_str[i] = str[i];
    }
    new_str[len] = '\0';
    return new_str;
}
