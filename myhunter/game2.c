/*
** EPITECH PROJECT, 2024
** mysfkjgf
** File description:
** qiejvf
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <SFML/Audio.h>
#include "my.h"

int error_gestion_game(sfRenderWindow *window, sfTexture *texture)
{
    if (!window || !texture) {
        return -1;
    }
    return 0;
}

void update_game_state(game_resources_t *res)
{
    if (res->life <= 0) {
        sfRenderWindow_close(res->window);
        open_window_game_over();
    }
}

int load_game_resources(game_resources_t *res)
{
    sfTexture *texture;

    texture = sfTexture_createFromFile("asset/fond_nuit.jpg", NULL);
    if (!texture) {
        my_putstr("Failed to load background texture\n");
        return -1;
    }
    res->background = sfSprite_create();
    res->duck = duck_sprite();
    res->font = sfFont_createFromFile("asset/ARIAL.TTF");
    if (!res->font || !res->duck) {
        my_putstr("Failed to load sprite or font\n");
        return -1;
    }
    res->score = 0;
    res->life = 3;
    sfSprite_setTexture(res->background, texture, sfTrue);
    return 0;
}

int initialize_window_game(game_resources_t *res)
{
    if (initialize_window_and_music(res) == -1) {
        return -1;
    }
    if (initialize_game_resources(res) == -1) {
        return -1;
    }
    return 0;
}

void handle_game_events(sfRenderWindow *window, sfEvent *event, int *life)
{
    if (event->type == sfEvtClosed || (event->type == sfEvtKeyPressed
        && event->key.code == sfKeyEscape)) {
        sfRenderWindow_close(window);
    }
    if (*life == 0) {
        sfRenderWindow_close(window);
        open_window_game_over();
    }
}
