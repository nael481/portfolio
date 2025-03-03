/*
** EPITECH PROJECT, 2024
** ll
** File description:
** printf
*/

int my_long_long_putnbr(long long n)
{
    if (n < 0) {
        my_putchar('-');
        n = -n;
    }
    if (n / 10 > 0)
        my_putnbr(n / 10);
    my_putchar((n % 10) + '0');
}
