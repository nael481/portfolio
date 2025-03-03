/*
** EPITECH PROJECT, 2024
** organized
** File description:
** str_to_int
*/

int str_to_int(const char *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result * sign;
}
