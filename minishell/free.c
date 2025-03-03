/*
** EPITECH PROJECT, 2025
** shell1
** File description:
** shell1
*/

#include "my.h"

void free_all(char *line, char *prev_path)
{
    free(line);
    free(prev_path);
}
