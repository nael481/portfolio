/*
** EPITECH PROJECT, 2024
** organized
** File description:
** sort
*/
#include "shell.h"
#include "my.h"

int sort(void *data, char **args)
{
    material_t **head = (material_t **)data;
    int reverse = fc_reverse(args);

    if (len_args(args) == 0)
        return 84;
    switch (args[0][0]) {
    case 'I':
        insertion_sort(head, 'I', reverse);
        break;
    case 'N':
        insertion_sort(head, 'N', reverse);
        break;
    case 'T':
        insertion_sort(head, 'T', reverse);
        break;
    default:
        mini_printf("Error: Unsupported sort type '%s'.\n", args[0]);
        return 84;
    }
    return 0;
}

int fc_reverse(char **args)
{
    int reverse = 0;

    if (args[1] != NULL && my_strcmp(args[1], "-r") == 0)
        reverse = 1;
    return reverse;
}
