/*
** EPITECH PROJECT, 2024
** ll
** File description:
** printf
*/


void long_long_hexa_min(long long decimal)
{
    char nombre[] = "0123456789abcdef";
    char result[50];
    int i = 0;
    long a = 0;

    if (decimal == 0) {
        my_putchar('0');
        return;
    }
    while (decimal != 0) {
        i = decimal % 16;
        result[a] = nombre[i];
        a++;
        decimal /= 16;
    }
    result[a] = '\0';
    my_revstr(result, a);
    for (int j = 0; result[j] != '\0'; j++) {
        my_putchar(result[j]);
    }
}