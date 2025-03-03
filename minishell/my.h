/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** robj
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stdarg.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>

#ifndef MY_H
    #define MY_H

// Basic utility functions
void my_putchar(char c);
int my_putstr(char const *str);
int my_putnbr(int n);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char const *src);
int my_strlen(char const *str);
char *my_strchr(const char *str, int c);

// Environment variable functions
char *my_getenv(const char *name, char **env);

// String comparison functions
int my_strncmp(char const *s1, char const *s2, int n);

// Path and command execution functions
int build_full_path(char *dir, char *command, char *full_path);
int build_full_path_in_directory(char *dir, char *command, char *full_path);
int execute_full_path(char *full_path, char **args, char **env);
int find_command_in_path(char *command, char **args, char **env);
void execute_absolute_command(char *command, char **args, char **env);
int is_executable(char *path);
void execute_command(char *command, char **args, char **env, int *status);
pid_t create_child_process(void);

// Shell built-in commands
void cd_command(char **args, char **env, char **prev_path);

// Shell loop and command handling
void prompt(void);
void free_all(char *line, char *prev_path);
void signal_handler(int signal);
void handle_exit_status(int status, int *exit_status);
void handle_command(char **args, char **env, char **prev_path, int *exit_status);
void run_shell_loop(char **env);

// Input and parsing functions
int read_input(char **line, size_t *len);
void parse_command(char *line, char **args);

// Print functions
int mini_printf(const char *param, ...);

// Main function
int main(int argc, char **argv, char **env);

#endif /* !MY_H */
