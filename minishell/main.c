/*
** EPITECH PROJECT, 2025
** main
** File description:
** shell1
*/

#include "my.h"

pid_t create_child_process(void)
{
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    }
    return pid;
}

void remove_newline(char *line)
{
    int i = 0;

    while (line[i] != '\0') {
        i++;
    }
    if (i > 0 && line[i - 1] == '\n') {
        line[i - 1] = '\0';
    }
}

int read_input(char **line, size_t *len)
{
    if (getline(line, len, stdin) == -1) {
        return 0;
    }
    remove_newline(*line);
    return 1;
}

void parse_command(char *line, char **args)
{
    int i = 0;
    char *command = strtok(line, "  \t");

    while (command != NULL){
        args[i] = command;
        command = strtok(NULL, " \t");
        i++;
    }
    args[i] = NULL;
}

int main(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;
    run_shell_loop(env);
    return 0;
}
