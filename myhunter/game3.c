/*
** EPITECH PROJECT, 2024
** PZAIHOEZIU
** File description:
** ZFAXK,BVRH
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <SFML/Audio.h>
#include "my.h"

void game_loop(game_resources_t *res)
{
    sfEvent event;
    char score_str[20];
    char life_str[20];

    while (sfRenderWindow_isOpen(res->window)) {
        while (sfRenderWindow_pollEvent(res->window, &event)) {
            handle_game_events(res->window, &event, &res->life);
        }
        update_game_objects(res);
        display_texts(res, score_str, life_str);
        render_game(res);
    }
}

int initialize_window_and_music(game_resources_t *res)
{
    sfVideoMode mode = {1920, 1080, 64};

    res->window = sfRenderWindow_create(mode,
        "MY_HUNTER", sfResize | sfClose, NULL);
    if (!res->window) {
        my_putstr("Failed to create window\n");
        return -1;
    }
    res->music = initialize_music();
    if (!res->music) {
        my_putstr("Failed to initialize music\n");
        return -1;
    }
    sfMusic_setVolume(res->music, 50);
    sfMusic_setLoop(res->music, sfTrue);
    sfMusic_play(res->music);
    return 0;
}

int initialize_game_resources(game_resources_t *res)
{
    sfVector2f scale = {1.5, 1};

    if (load_game_resources(res) == -1) {
        return -1;
    }
    sfSprite_setScale(res->background, scale);
    initialize_texts(&res->score_text,
        &res->life_text, res->font, res->window);
    return 0;
}

void update_game_objects(game_resources_t *res)
{
    animate_and_move_sprite(res->duck, res->window, &res->life, &res->score);
}
