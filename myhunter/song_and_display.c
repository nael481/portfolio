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

void display_score(sfRenderWindow *window, int score, sfText *text)
{
    char score_text[20] = "Score: ";
    char score_value[10];

    int_to_str(score, score_value);
    my_strcat(score_text, score_value);
    sfText_setString(text, score_text);
    sfRenderWindow_drawText(window, text, NULL);
}

void display_life(sfRenderWindow *window, int life, sfText *life_text)
{
    char life_text_str[20] = "Life: ";
    char life_value[10];

    int_to_str(life, life_value);
    my_strcat(life_text_str, life_value);
    sfText_setString(life_text, life_text_str);
    sfRenderWindow_drawText(window, life_text, NULL);
}

void initialize_texts(sfText **score_text, sfText **life_text,
    sfFont *font, sfRenderWindow *window)
{
    sfVector2f life_position = {sfRenderWindow_getSize(window).x - 150, 10};

    *score_text = sfText_create();
    *life_text = sfText_create();
    if (!*score_text || !*life_text) {
        my_putstr("Failed to create text objects\n");
        return;
    }
    if (!font) {
        my_putstr("Font loading failed\n");
        return;
    }
    sfText_setFont(*score_text, font);
    sfText_setCharacterSize(*score_text, 50);
    sfText_setColor(*score_text, sfWhite);
    sfText_setFont(*life_text, font);
    sfText_setCharacterSize(*life_text, 50);
    sfText_setColor(*life_text, sfWhite);
    sfText_setPosition(*life_text, life_position);
}

sfMusic *initialize_music(void)
{
    sfMusic *music = sfMusic_createFromFile("retro_song.mp3");

    if (!music) {
        my_putstr("Failed to load music\n");
        return NULL;
    }
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    return music;
}
