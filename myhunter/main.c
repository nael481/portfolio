/*
** EPITECH PROJECT, 2024
** MY_HUNTER
** File description:
** MAIN
*/

#include "my.h"
int main(int argc, char **argv)
{
    if (argc == 1) {
        open_window();
    }
    if (argc > 1) {
        if (argv[1][0] == '-' && argv[1][1] == 'h'){
            my_putstr("Duck Hunt est un jeu de tir");
            my_putstr(" où le joueur doit abattre des canards \n");
            my_putstr("qui apparaissent à l’écran avant");
            my_putstr(" avant qu’ils ne s’échappent.\n");
            my_putstr("Chaque canard touché rapporte des points.\n");
            my_putstr("Si trop de canards sont manqués,");
            my_putstr(" la partie est terminée\n");
            } else
                return 84;
    }
    return 0;
}
