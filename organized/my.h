/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** organized
*/

#include <stdarg.h>
#include <string.h>
#include <unistd.h>

#ifndef MY_H
    #define MY_H

// Structure definitions
typedef struct material {
    int id;
    int current_id;
    char *name;
    char *type;
    struct material *next;
} material_t;

// String utility functions
int my_strlen(char const *str);
char *my_strdup(const char *str);
int my_strcmp(char const *s1, char const *s2);
void my_strcat(char *dest, const char *src);
void my_revstr(char *str, int i);

// Print functions
void flag(char param, va_list ap);
int mini_printf(const char *format, ...);
int my_putchar(char character);
int my_putnbr(int n);
int my_putstr(char const *str);

// Conversion functions
int str_to_int(const char *str);
void int_to_str_reverse(int num, char *str, int *length);
void reverse_and_finalize_str(char *str, int length, int is_negative);
void int_to_str(int num, char *str);

// Material management functions
int get_and_update_max_id(material_t *head);
material_t *find_material_by_id(material_t *head, int id);
int is_material_to_delete(material_t *current, material_t *to_delete);
void disconnect_material(material_t **head, material_t *previous, material_t *current);
void free_material(material_t *to_delete);
void delete_material(material_t **head, material_t *to_delete);

// Sorting functions
int fc_comp(material_t *node, material_t *next, char crit);
void insert_sort_crit(material_t **head, material_t *node, char crit, int reverse);
void insertion_sort(material_t **head, char crit, int reverse);
material_t *find_insertion_point(material_t **head, material_t *node, char crit, int reverse);
void insert_node(material_t **head, material_t *node, material_t *prev, material_t *current);

// Argument handling functions
int len_args(char **args);
int fc_reverse(char **args);

#endif /* MY_H */
