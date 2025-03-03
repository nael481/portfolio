/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** my_hunter
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <SFML/Audio.h>
#include "my.h"


void display_texts(game_resources_t *res, char *score_str, char *life_str)
{
    int_to_str(res->score, score_str);
    int_to_str(res->life, life_str);
    sfText_setString(res->score_text, score_str);
    sfText_setString(res->life_text, life_str);
}

void render_game(game_resources_t *res)
{
    sfRenderWindow_clear(res->window, sfBlack);
    sfRenderWindow_drawSprite(res->window, res->background, NULL);
    sfRenderWindow_drawSprite(res->window, res->duck->sprite, NULL);
    sfRenderWindow_drawText(res->window, res->score_text, NULL);
    sfRenderWindow_drawText(res->window, res->life_text, NULL);
    sfRenderWindow_display(res->window);
}

void cleanup_resources(game_resources_t *res)
{
    sfSprite_destroy(res->duck->sprite);
    sfTexture_destroy(res->duck->texture);
    sfClock_destroy(res->duck->clock);
    free(res->duck);
    sfText_destroy(res->score_text);
    sfText_destroy(res->life_text);
    sfFont_destroy(res->font);
    if (res->music) {
        sfMusic_stop(res->music);
        sfMusic_destroy(res->music);
    }
}

void render_window_game(game_resources_t *res)
{
    if (initialize_window_game(res) == -1) {
        my_putstr("Failed to load resources\n");
        return;
    }
    game_loop(res);
    cleanup_resources(res);
}

void window_game(void)
{
    game_resources_t res = {0};

    srand(time(NULL));
    render_window_game(&res);
}
