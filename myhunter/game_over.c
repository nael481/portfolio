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
#include "my.h"
#include <SFML/System.h>

sfRenderWindow *create_game_over_window(void)
{
    sfVideoMode mode = {2160, 3840, 64};

    return sfRenderWindow_create(mode, "Game Over",
        sfResize | sfClose, NULL);
}

sfSprite *create_game_over_sprite(void)
{
    sfTexture *texture = sfTexture_createFromFile("asset/game_over.jpg", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {4, 4};

    if (!texture)
        return NULL;
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

void handle_game_over_events(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
            event.key.code == sfKeyEscape)) {
            sfRenderWindow_close(window);
        }
    }
}

void display_game_over_screen(sfRenderWindow *window, sfSprite *sprite)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_display(window);
}

void open_window_game_over(void)
{
    sfRenderWindow *window = create_game_over_window();
    sfSprite *sprite = create_game_over_sprite();

    if (!window)
        return;
    if (!sprite) {
        sfRenderWindow_destroy(window);
        return;
    }
    while (sfRenderWindow_isOpen(window)) {
        handle_game_over_events(window);
        display_game_over_screen(window, sprite);
    }
    sfSprite_destroy(sprite);
    sfRenderWindow_destroy(window);
}
