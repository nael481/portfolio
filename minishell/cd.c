/*
** EPITECH PROJECT, 2025
** shell1
** File description:
** shel1
*/

#include "my.h"

char *get_target_path(char **args, char **env, char *prev_path)
{
    char *home = my_getenv("HOME", env);

    if (!args[1] || my_strcmp(args[1], "~") == 0) {
        if (!home) {
            write(2, "cd: HOME not set\n", 17);
            return NULL;
        }
        return home;
    }
    if (my_strcmp(args[1], "-") == 0) {
        if (!prev_path) {
            write(2, "cd: OLDPWD not set\n", 19);
            return NULL;
        }
        return prev_path;
    }
    return args[1];
}

char *update_previous_path(void)
{
    char cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd");
        return NULL;
    }
    return my_strdup(cwd);
}

void cd_command(char **args, char **env, char **prev_path)
{
    char *new_prev = update_previous_path();
    char *path = get_target_path(args, env, *prev_path);

    if (!path || !new_prev)
        return;
    if (chdir(path) != 0) {
        perror(args[1]);
    }
    free(*prev_path);
    *prev_path = new_prev;
}
