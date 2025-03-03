/*
** EPITECH PROJECT, 2024
** ercwvrfgy
** File description:
** rgbkvfrg
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include "my.h"

int error_gestion(sfRenderWindow *window, sfTexture *texture)
{
    if (!window || !texture) {
        return -1;
    }
    return 0;
}

int initialize_window(
    sfRenderWindow **window,
    sfSprite **sprite,
    sfTexture **texture
)
{
    sfVideoMode mode = {1920, 1080, 64};
    sfVector2f scale = {1, 1};

    *window = sfRenderWindow_create(mode, "MY_HUNTER",
    sfResize | sfClose, NULL);
    *texture = sfTexture_createFromFile("asset/back.jpg", NULL);
    if (error_gestion(*window, *texture) == -1)
        return -1;
    *sprite = sfSprite_create();
    sfSprite_setTexture(*sprite, *texture, sfTrue);
    sfSprite_setScale(*sprite, scale);
    return 0;
}

void destroy_all(resources_t *res)
{
    sfSprite_destroy(res->sprite);
    sfTexture_destroy(res->texture);
    sfSprite_destroy(res->button);
    sfTexture_destroy(res->button_texture);
    sfSprite_destroy(res->exit_button);
    sfTexture_destroy(res->exit_button_texture);
    sfSprite_destroy(res->title_sprite);
    sfTexture_destroy(res->title_texture);
    sfRenderWindow_destroy(res->window);
}
