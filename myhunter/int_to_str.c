/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** my_hunter
*/

void int_to_str_reverse(int num, char *str, int *length)
{
    int i = 0;
    char char_digit;
    int digit;

    if (num < 0) {
        num = -num;
    }
    do {
        digit = num % 10;
        char_digit = digit + '0';
        str[i] = char_digit;
        i++;
        num = num / 10;
    } while (num > 0);
    *length = i;
}

void reverse_and_finalize_str(char *str, int length, int is_negative)
{
    char temp;

    if (is_negative) {
        for (int j = length; j > 0; j--) {
            str[j] = str[j - 1];
        }
        str[0] = '-';
        length++;
    }
    str[length] = '\0';
    for (int j = 0; j < length / 2; j++) {
        temp = str[j];
        str[j] = str[length - j - 1];
        str[length - j - 1] = temp;
    }
}

void int_to_str(int num, char *str)
{
    int is_negative = 0;
    int length = 0;

    if (num < 0) {
        is_negative = 1;
    }
    int_to_str_reverse(num, str, &length);
    reverse_and_finalize_str(str, length, is_negative);
}
