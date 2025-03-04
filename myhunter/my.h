/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** my_hunter
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <SFML/Audio.h>

#ifndef MY_H_
    #define MY_H_

// Structures
typedef struct sprite {
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *clock;
    sfVector2f position;
    int frame;
} sprite_t;

typedef struct button_properties {
    sfVector2f scale;
    sfVector2f position;
} button_properties_t;

typedef struct {
    sfRenderWindow *window;
    sfSprite *sprite;
    sfTexture *texture;
} window_t;

typedef struct {
    sfSprite *button;
    sfTexture *button_texture;
    sfSprite *exit_button;
    sfTexture *exit_button_texture;
    sfSprite *title_sprite;
    sfTexture *title_texture;
} assets_t;

typedef struct {
    sfRenderWindow *window;
    sfSprite *sprite;
    sfTexture *texture;
    sfSprite *button;
    sfTexture *button_texture;
    sfSprite *exit_button;
    sfTexture *exit_button_texture;
    sfSprite *title_sprite;
    sfTexture *title_texture;
    sfMusic *music;
    sfSound *shot_sound;
    sfSound *duck_sound;
} resources_t;

typedef struct game_resources {
    sfRenderWindow *window;
    sfSprite *background;
    sprite_t *duck;
    sfText *score_text;
    sfText *life_text;
    sfFont *font;
    sfMusic *music;
    int score;
    int life;
} game_resources_t;

// Window management functions
sfRenderWindow *create_game_over_window(void);
sfSprite *create_game_over_sprite(void);
void handle_game_over_events(sfRenderWindow *window);
void display_game_over_screen(sfRenderWindow *window, sfSprite *sprite);
void open_window_game_over(void);
void render_window_game(game_resources_t *res);
void window_game(void);
int initialize_window_game(game_resources_t *res);
int initialize_window(sfRenderWindow **window, sfSprite **sprite, sfTexture **texture);
int open_window(void);

// Resource management functions
void cleanup_resources(game_resources_t *res);
int load_game_resources(game_resources_t *res);
int initialize_all(resources_t *res);
void destroy_all(resources_t *res);

// Game management functions
void display_texts(game_resources_t *res, char *score_str, char *life_str);
void render_game(game_resources_t *res);
void update_game_state(game_resources_t *res);
void handle_game_events(sfRenderWindow *window, sfEvent *event, int *life);
void game_loop(game_resources_t *res);
void update_game_objects(game_resources_t *res);

// Event handling functions
void handle_events(resources_t *res, sfEvent *event);

// Initialization functions
int initialize_title(sfSprite **title_sprite, sfTexture **title_texture);
int initialize_button(sfSprite **button, sfTexture **button_texture);
int initialize_exit_button(sfSprite **exit_button, sfTexture **exit_button_text);
int initialize_window_and_music(game_resources_t *res);
int initialize_game_resources(game_resources_t *res);
sfMusic *initialize_music(void);
void initialize_texts(sfText **score_text, sfText **life_text, sfFont *font, sfRenderWindow *window);

// Utility functions
void int_to_str_reverse(int num, char *str, int *length);
void reverse_and_finalize_str(char *str, int length, int is_negative);
void int_to_str(int num, char *str);
void my_strcat(char *dest, const char *src);
int my_putchar(char c);
int my_putstr(char const *str);

// Game-specific functions
sprite_t *allocate_duck(void);
int load_duck_texture(sprite_t *duck, const char *filepath);
int create_duck_sprite(sprite_t *duck);
int initialize_duck_clock(sprite_t *duck);
sprite_t *duck_sprite(void);
void life_game(sprite_t *duck, sfRenderWindow *window, int *life);
void animate_and_move_sprite(sprite_t *duck, sfRenderWindow *window, int *life, int *score);
void sprite_clique(sprite_t *duck, sfFloatRect sprite_bounds, sfVector2i mouse_pos, int *score);

// Error handling functions
int error_gestion_game(sfRenderWindow *window, sfTexture *texture);
int error_gestion(sfRenderWindow *window, sfTexture *texture);

// Main function
int main(int argc, char **argv);

#endif /* MY_H_ */
