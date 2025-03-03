/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** my_hunter
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include "my.h"


int initialize_title(sfSprite **title_sprite, sfTexture **title_texture)
{
    sfVector2f position = {500, 50};
    sfVector2f scale = {2, 2};

    *title_texture = sfTexture_createFromFile("image_my_hunter.png", NULL);
    if (!*title_texture) {
        return -1;
    }
    *title_sprite = sfSprite_create();
    if (!*title_sprite) {
        sfTexture_destroy(*title_texture);
        return -1;
    }
    sfSprite_setTexture(*title_sprite, *title_texture, sfTrue);
    sfSprite_setPosition(*title_sprite, position);
    sfSprite_setScale(*title_sprite, scale);
    return 0;
}

int initialize_all(resources_t *res)
{
    if (initialize_window(&res->window, &res->sprite, &res->texture) == -1)
        return -1;
    if (initialize_button(&res->button, &res->button_texture) == -1)
        return -1;
    if (initialize_exit_button(&res->exit_button,
        &res->exit_button_texture) == -1)
        return -1;
    if (initialize_title(&res->title_sprite, &res->title_texture) == -1)
        return -1;
    return 0;
}

void handle_events(resources_t *res, sfEvent *event)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(res->window);
    sfFloatRect button_bounds = sfSprite_getGlobalBounds(res->button);
    sfFloatRect exit_button_bounds =
        sfSprite_getGlobalBounds(res->exit_button);

    if (event->type == sfEvtClosed)
        sfRenderWindow_close(res->window);
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape)
        sfRenderWindow_close(res->window);
    if (event->type == sfEvtMouseButtonPressed) {
        if (sfFloatRect_contains(&button_bounds, mouse_pos.x, mouse_pos.y)) {
            sfRenderWindow_close(res->window);
            window_game();
        }
        if (sfFloatRect_contains(&exit_button_bounds,
            mouse_pos.x, mouse_pos.y)) {
            sfRenderWindow_close(res->window);
        }
    }
}

void render_window(resources_t *res)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(res->window)) {
        while (sfRenderWindow_pollEvent(res->window, &event)) {
            handle_events(res, &event);
        }
        sfRenderWindow_clear(res->window, sfBlack);
        sfRenderWindow_drawSprite(res->window, res->sprite, NULL);
        sfRenderWindow_drawSprite(res->window, res->title_sprite, NULL);
        sfRenderWindow_drawSprite(res->window, res->button, NULL);
        sfRenderWindow_drawSprite(res->window, res->exit_button, NULL);
        sfRenderWindow_display(res->window);
    }
}

int open_window(void)
{
    resources_t res = {0};

    if (initialize_all(&res) == -1) {
        return 84;
    }
    render_window(&res);
    destroy_all(&res);
    return 0;
}
