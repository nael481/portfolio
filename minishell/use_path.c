/*
** EPITECH PROJECT, 2025
** shell1
** File description:
** shell21
*/

#include "my.h"

int build_full_path(char *dir, char *command, char *full_path)
{
    int i = 0;
    int j = 0;

    while (dir[i] != '\0') {
        full_path[i] = dir[i];
        i++;
    }
    full_path[i] = '/';
    i++;
    while (command[j] != '\0') {
        full_path[i + j] = command[j];
        j++;
    }
    full_path[i + j] = '\0';
    return i + j;
}

int build_full_path_in_directory(char *dir, char *command, char *full_path)
{
    int i = 0;
    int j = 0;

    while (dir[i] != '\0') {
        full_path[i] = dir[i];
        i++;
    }
    full_path[i] = '/';
    i++;
    while (command[j] != '\0') {
        full_path[i + j] = command[j];
        j++;
    }
    full_path[i + j] = '\0';
    return 0;
}

int execute_full_path(char *full_path, char **args, char **env)
{
    if (is_executable(full_path)) {
        execve(full_path, args, env);
        perror("execve");
        exit(1);
    }
    return 0;
}

int find_command_in_path(char *command, char **args, char **env)
{
    char *path = my_getenv("PATH", env);
    char *path_copy;
    char *dir;
    char full_path[1024];

    if (path != NULL) {
        path_copy = my_strdup(path);
        dir = strtok(path_copy, ":");
        while (dir != NULL) {
            build_full_path_in_directory(dir, command, full_path);
            execute_full_path(full_path, args, env);
            dir = strtok(NULL, ":");
        }
        free(path_copy);
    }
    return 0;
}
