/*
** EPITECH PROJECT, 2024
** organized
** File description:
** del
*/

#include "my.h"
#include "shell.h"

int del(void *data, char **args)
{
    material_t **head = (material_t **)data;
    material_t *to_delete;
    int id_to_delete;
    int i;

    for (i = 0; args[i] != NULL; i++) {
        id_to_delete = str_to_int(args[i]);
        to_delete = find_material_by_id(*head, id_to_delete);
        if (to_delete != NULL) {
            delete_material(head, to_delete);
        }
    }
    return 0;
}
