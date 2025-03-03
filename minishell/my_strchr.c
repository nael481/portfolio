/*
** EPITECH PROJECT, 2025
** shelle
** File description:
** fgh
*/

#include <stddef.h>
#include "my.h"

char *my_strchr(const char *str, int c)
{
    while (*str) {
        if (*str == (char)c) {
            return (char *)str;
        }
        str++;
    }
    if (c == '\0') {
        return (char *)str;
    }
    return NULL;
}
