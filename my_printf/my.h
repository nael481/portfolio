/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** ###
*/
#include <stdarg.h>
#ifndef MY_H_
    #define MY_H_

// Conversion functions
int octal(unsigned int decimal);
void hexa_maj(int decimal);
void hexa_min(int decimal);
int modulo_p(int adresse);
int long_octal(unsigned long decimal);
void long_hexa_maj(long decimal);
void long_hexa_min(long decimal);
void format(char param, va_list ap);

// Scientific notation functions
int ecriture_scientifique(double nb);
int maj_ecriture_scientifique(double nb);
int afficher_en_scientifique_maj(double nb, int exposant);
int convertir_exposant(double *nb);
int afficher_en_scientifique(double nb, int exposant);
int long_convertir_exposant(long *nb);

// Print functions
int my_printf(const char *format, ...);
int my_putchar(char c);
int my_putnbr(int n);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_putdouble(double nb);
int my_putfloat(float nb);
int long_my_putdouble(long nb);
int my_long_putnbr(long n);

// Utility functions
void my_swap(char *a, char *b);
void my_revstr(char *str, int i);
int sup_10(double *nb);

// Flag handling functions
void flag3(char param, va_list ap);
void flag2(char param, va_list ap);
void flag(char param, va_list ap);
void forma(char param);

#endif /* MY_H_ */
