# Minishell

**Description**: Minishell 1 is a minimalist UNIX command interpreter based on **TCSH**. It is a first step towards the **42sh** project, aimed at understanding and implementing the basics of a shell.

**Features**:
- Display a prompt and execute commands from the PATH or absolute path
- Error handling and appropriate message display
- Implementation of builtins: `cd`, `setenv`, `unsetenv`, `env`, `exit`
- Environment and PATH management
- Respect for the return codes of executed commands

**Compilation**:
```bash
make        # Compilation
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Full recompilation
```

**Usage**:
```bash
./mysh
```

Example usage:
```bash
$> pwd
/tmp
$> cd /home
$> pwd
/home
$> ls -l
total 72
drwxr-xr-x 2 user user 4096 Jan 6 17:24 Documents
$> exit
```

**Author**: Nael Gamba - Student at Epitech