/*
** EPITECH PROJECT, 2025
** shell1
** File description:
** shell1
*/

#include "my.h"


void handle_exit_status(int status, int *exit_status)
{
    if (WIFEXITED(status)) {
        *exit_status = WEXITSTATUS(status);
    } else if (WIFSIGNALED(status)) {
        *exit_status = 128 + WTERMSIG(status);
    }
}

void handle_command(char **args, char **env,
    char **prev_path, int *exit_status)
{
    int status = 0;

    if (my_strcmp(args[0], "exit") == 0)
        exit(*exit_status);
    if (my_strcmp(args[0], "cd") == 0) {
        cd_command(args, env, prev_path);
    } else {
        execute_command(args[0], args, env, &status);
        handle_exit_status(status, exit_status);
    }
}

void run_shell_loop(char **env)
{
    char *line = NULL;
    size_t len = 0;
    char *args[1024];
    char *prev_path = NULL;
    int exit_status = 0;

    while (1) {
        if (!read_input(&line, &len))
            break;
        parse_command(line, args);
        if (args[0] != NULL)
            handle_command(args, env, &prev_path, &exit_status);
    }
    free_all(line, prev_path);
    exit(exit_status);
}
