/*
** EPITECH PROJECT, 2025
** shell1
** File description:
** shell1
*/

#include "my.h"

int is_executable(char *path)
{
    struct stat statbuf;

    if (stat(path, &statbuf) == 0 && S_ISREG(statbuf.st_mode)
        && (statbuf.st_mode & S_IXUSR)) {
        return 1;
    }
    return 0;
}

void signal_handle(int status)
{
    int signal;

    if (WIFSIGNALED(status)) {
        signal = WTERMSIG(status);
        my_putstr(strsignal(signal));
        my_putstr("\n");
    }
}

void execute_command(char *command, char **args, char **env, int *status)
{
    pid_t pid = create_child_process();

    if (pid == 0) {
        if (command[0] == '/' || command[0] == '.'
            || my_strchr(command, '/')) {
            execute_absolute_command(command, args, env);
            exit(127);
        }
        if (!find_command_in_path(command, args, env)) {
            my_putstr(args[0]);
            write(2, ": Command not found.\n", 21);
            exit(127);
        }
        exit(0);
    } else if (pid < 0) {
        perror("fork");
    } else {
        waitpid(pid, status, WUNTRACED);
        signal_handle(*status);
    }
}
