/*
** EPITECH PROJECT, 2024
** ll
** File description:
** printf
*/

#include <stdio.h>
#include "my.h"

int long_long_octal(unsigned long long decimal)
{
    char oct[] = "01234567";
    int i = 0;
    char buffer[20];

    if (decimal == 0){
        buffer[i] = '0';
        buffer[i + 1] = '\0';
        my_putstr(buffer);
    }
    while (decimal > 0) {
        buffer[i] = oct[decimal % 8];
        i++;
        decimal = decimal / 8;
    }
    buffer[i] = '\0';
    my_revstr(buffer, i);
}
