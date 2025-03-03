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

int initialize_button_generic(sfSprite **button, sfTexture **button_texture,
    const char *file, button_properties_t props)
{
    *button_texture = sfTexture_createFromFile(file, NULL);
    if (!*button_texture) {
        return -1;
    }
    *button = sfSprite_create();
    if (!*button) {
        sfTexture_destroy(*button_texture);
        return -1;
    }
    sfSprite_setTexture(*button, *button_texture, sfTrue);
    sfSprite_setScale(*button, props.scale);
    sfSprite_setPosition(*button, props.position);
    return 0;
}

int initialize_button(sfSprite **button, sfTexture **button_texture)
{
    button_properties_t props = {{0.5, 0.5}, {800, 400}};

    return initialize_button_generic(button, button_texture,
        "asset/start_button.png", props);
}

int initialize_exit_button(sfSprite **exit_button,
    sfTexture **exit_button_text)
{
    button_properties_t props = {{0.5, 0.5}, {800, 600}};

    return initialize_button_generic(exit_button, exit_button_text,
        "asset/exit_button1.png", props);
}
