/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** organized
*/

#include <stdarg.h>
#include <unistd.h>

#ifndef MY_H
    #define MY_H
typedef struct material {
    int id;
    int current_id;
    char *name;
    char *type;
    struct material *next;
} material_t;

int my_strlen(char const *str);
char *my_strdup(const char *str);
void flag(char param, va_list ap);
int mini_printf(const char *format, ...);
int my_putchar(char character);
int my_putnbr(int n);
int my_putstr(char const *str);
void my_revstr(char *str, int i);
int get_and_update_max_id(material_t *head);
int my_strcmp(char const *s1, char const *s2);
int str_to_int(const char *str);
material_t *find_material_by_id(material_t *head, int id);
int is_material_to_delete(material_t *current, material_t *to_delete);
void disconnect_material(material_t **head,
    material_t *previous, material_t *current);
void free_material(material_t *to_delete);
void delete_material(material_t **head, material_t *to_delete);
int fc_comp(material_t *node, material_t *next, char crit);
void insert_sort_crit(material_t **head, material_t *node,
    char crit, int reverse);
void insertion_sort(material_t **head, char crit, int reverse);
int fc_reverse(char **args);
material_t *find_insertion_point(material_t **head,
    material_t *node, char crit, int reverse);
void insert_node(material_t **head, material_t *node,
    material_t *prev, material_t *current);
int len_args(char **args);
#endif
