/*
** EPITECH PROJECT, 2024
** organized
** File description:
** organized
*/

#include "shell.h"
#include <stddef.h>
#include "my.h"
#include <stdlib.h>

int main(void)
{
    material_t *list = NULL;

    workshop_shell(&list);
    free(list);
    return 0;
}
