/*
** EPITECH PROJECT, 2025
** shell1
** File description:
** shell1
*/

#include "my.h"

void execute_absolute_command(char *command, char **args, char **env)
{
    if (access(command, X_OK) == -1){
        write(2, "Permission denied.\n", 19);
        exit(126);
        }
    if (is_executable(command)) {
        execve(command, args, env);
        perror("execve");
    } else {
        exit(1);
    }
}
