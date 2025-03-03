/*
** EPITECH PROJECT, 2024
** jéefrbh
** File description:
** k,defbh
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "my.h"
#include <SFML/System.h>

void life_game(sprite_t *duck, sfRenderWindow *window, int *life)
{
    if (duck->position.x >= 1920) {
        duck->position.x = -280;
        duck->position.y = rand() % 580;
        (*life)--;
    }
    if (*life == 0) {
        sfRenderWindow_close(window);
        open_window_game_over();
    }
}

void animate_and_move_sprite(sprite_t *duck,
    sfRenderWindow *window, int *life, int *score)
{
    sfTime time = sfClock_getElapsedTime(duck->clock);
    float seconds = time.microseconds / 1000000.0;
    sfIntRect rect = {110 * duck->frame, 0, 110, 110};
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect sprite_bounds = sfSprite_getGlobalBounds(duck->sprite);
    float speed = 0.5 + (*score) * 0.05;

    if (seconds > 0.1) {
        duck->frame = (duck->frame + 1) % 3;
        sfSprite_setTextureRect(duck->sprite, rect);
        sfClock_restart(duck->clock);
    }
    duck->position.x += speed;
    sprite_clique(duck, sprite_bounds, mouse_pos, score);
    life_game(duck, window, life);
    sfSprite_setPosition(duck->sprite, duck->position);
}

void sprite_clique(sprite_t *duck, sfFloatRect sprite_bounds,
    sfVector2i mouse_pos, int *score)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfFloatRect_contains(&sprite_bounds, mouse_pos.x, mouse_pos.y)) {
        duck->position.x = -280;
        duck->position.y = rand() % 580;
        (*score)++;
    }
}
