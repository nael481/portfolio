/*
** EPITECH PROJECT, 2024
** organized
** File description:
** sort
*/
#include "shell.h"
#include "my.h"

int fc_comp(material_t *node, material_t *next, char crit)
{
    int comp;

    if (crit == 'N') {
        comp = my_strcmp(node->name, next->name);
    } else if (crit == 'T') {
        comp = my_strcmp(node->type, next->type);
    } else {
        comp = (node->id > next->id) ? 1 : -1;
    }
    return comp;
}

material_t *find_insertion_point(material_t **head,
    material_t *node, char crit, int reverse)
{
    material_t *prev = NULL;
    material_t *current = *head;
    int comp;

    while (current != NULL) {
        comp = fc_comp(current, node, crit);
        if (reverse) {
            comp = -comp;
        }
        if (comp >= 0) {
            break;
        }
        prev = current;
        current = current->next;
    }
    return prev;
}

void insert_node(material_t **head, material_t *node,
    material_t *prev, material_t *current)
{
    if (prev == NULL) {
        node->next = *head;
        *head = node;
    } else {
        prev->next = node;
        node->next = current;
    }
}

void insert_sort_crit(material_t **head, material_t *node,
    char crit, int reverse)
{
    material_t *prev = find_insertion_point(head, node, crit, reverse);
    material_t *current;

    if (prev == NULL) {
        current = *head;
    } else {
        current = prev->next;
    }
    insert_node(head, node, prev, current);
}

void insertion_sort(material_t **head, char crit, int reverse)
{
    material_t *sorted = NULL;
    material_t *current = *head;
    material_t *next;

    while (current != NULL) {
        next = current->next;
        insert_sort_crit(&sorted, current, crit, reverse);
        current = next;
    }
    *head = sorted;
}
