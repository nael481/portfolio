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
#include "my.h"
#include <SFML/System.h>

sprite_t *allocate_duck(void)
{
    sprite_t *duck = malloc(sizeof(sprite_t));

    if (!duck) {
        my_putstr("Failed to allocate memory for duck\n");
        return NULL;
    }
    duck->position = (sfVector2f){0, 300};
    duck->frame = 0;
    return duck;
}

int load_duck_texture(sprite_t *duck, const char *filepath)
{
    duck->texture = sfTexture_createFromFile(filepath, NULL);
    if (!duck->texture) {
        my_putstr("Failed to load texture\n");
        free(duck);
        return -1;
    }
    return 0;
}

int create_duck_sprite(sprite_t *duck)
{
    duck->sprite = sfSprite_create();
    if (!duck->sprite) {
        my_putstr("Failed to create sprite\n");
        sfTexture_destroy(duck->texture);
        free(duck);
        return -1;
    }
    sfSprite_setTexture(duck->sprite, duck->texture, sfTrue);
    sfSprite_setTextureRect(duck->sprite, (sfIntRect){0, 0, 110, 110});
    return 0;
}

int initialize_duck_clock(sprite_t *duck)
{
    duck->clock = sfClock_create();
    if (!duck->clock) {
        my_putstr("Failed to create clock\n");
        sfSprite_destroy(duck->sprite);
        sfTexture_destroy(duck->texture);
        free(duck);
        return -1;
    }
    return 0;
}

sprite_t *duck_sprite(void)
{
    sprite_t *duck = allocate_duck();

    if (!duck)
        return NULL;
    if (load_duck_texture(duck, "sprite_canard.png") == -1)
        return NULL;
    if (create_duck_sprite(duck) == -1)
        return NULL;
    if (initialize_duck_clock(duck) == -1)
        return NULL;
    return duck;
}
