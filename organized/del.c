/*
** EPITECH PROJECT, 2024
** organized
** File description:
** del
*/

#include "my.h"
#include "shell.h"
#include <stdlib.h>

material_t *find_material_by_id(material_t *head, int id)
{
    material_t *current = head;

    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int is_material_to_delete(material_t *current, material_t *to_delete)
{
    return current == to_delete;
}

void disconnect_material(material_t **head,
    material_t *previous, material_t *current)
{
    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }
}

void free_material(material_t *to_delete)
{
    mini_printf("%s n°%d - \"%s\" deleted.\n",
        to_delete->type, to_delete->id, to_delete->name);
    free(to_delete->name);
    free(to_delete->type);
    free(to_delete);
}

void delete_material(material_t **head, material_t *to_delete)
{
    material_t *current = *head;
    material_t *previous = NULL;

    while (current != NULL) {
        if (is_material_to_delete(current, to_delete)) {
            disconnect_material(head, previous, current);
            free_material(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}
