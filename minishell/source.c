/*
** EPITECH PROJECT, 2024
** source
** File description:
** source
*/
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return 0;
}

int my_putnbr(int n)
{
    if (n < 0) {
        my_putchar('-');
        n = -n;
    }
    if (n > 9) {
        my_putnbr(n / 10);
        my_putchar((n % 10) + '0');
    } else {
        my_putchar(n + '0');
    }
    return 0;
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        i++;
    }
    return s1[i] - s2[i];
}

char *my_strdup(char const *src)
{
    int i = 0;
    char *str;

    if (src == NULL)
        return NULL;
    for (i = 0; src[i] != '\0'; i++);
    str = malloc(sizeof(char) * (i + 1));
    if (str == NULL)
        return NULL;
    for (i = 0; src[i] != '\0'; i++) {
        str[i] = src[i];
    }
    str[i] = '\0';
    return str;
}
