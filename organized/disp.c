/*
** EPITECH PROJECT, 2024
** organized
** File description:
** disp
*/

#include <stdlib.h>
#include "my.h"
#include "shell.h"

int disp(void *data, char **args)
{
    material_t *end = *(material_t **)data;

    while (end != NULL) {
        if (end->name != NULL && end->type != NULL){
            mini_printf("%s n°%d - \"%s\"\n",
                end->type, end->id, end->name);
        }
    end = end->next;
    }
    return 0;
}
