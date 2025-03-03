/*
** EPITECH PROJECT, 2024
** organized
** File description:
** add
*/
#include "my.h"
#include "shell.h"
#include <stdlib.h>

int get_and_update_max_id(material_t *head)
{
    int max_id = -1;
    material_t *current = head;

    while (current != NULL) {
        if (current->id > max_id)
            max_id = current->id;
        current = current->next;
    }
    return max_id + 1;
}

int len_args(char **args)
{
    int i = 0;

    for (i = 0; args[i] != NULL; i++);
    return i;
}

int is_valid_type(const char *type)
{
    char *valid_types[] = {
        "ACTUATOR",
        "DEVICE",
        "PROCESSOR",
        "SENSOR",
        "WIRE",
        "\0",
    };

    for (int i = 0; valid_types[i] != "\0"; i++) {
        if (my_strcmp(type, valid_types[i]) == 0) {
            return 0;
        }
    }
    return -1;
}

int init(char **args, material_t *new_node, material_t **head, int i)
{
        new_node->type = my_strdup(args[i]);
        new_node->name = my_strdup(args[i + 1]);
        new_node->id = get_and_update_max_id(*head);
}

int add(void *data, char **args)
{
    material_t **head = (material_t **)data;
    material_t *new_node;

    if (len_args(args) % 2 == 1)
        return 84;
    for (int i = 0; args[i] != NULL; i += 2) {
        if (is_valid_type(args[i]) == -1) {
            mini_printf("Error: Invalid type '%s'.\n", args[i]);
            exit(84);
        }
        new_node = malloc(sizeof(material_t));
        if (!new_node)
            return 84;
        init(args, new_node, head, i);
        new_node->next = *head;
        *head = new_node;
        mini_printf("%s n°%d - \"%s\" added.\n",
            new_node->type, new_node->id, new_node->name);
    }
    return 0;
}
