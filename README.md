# Portfolio

This project is the portfolio of Nael Gamba, a first-year student at Epitech.

## Description

This portfolio showcases the various projects and skills developed by Nael Gamba during his studies at Epitech. It includes code examples, completed projects, and information about Nael's skills and interests.

## Projects

### Project 1: Minishell

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

---

### Project 2: My_printf

**Description**: MY_PRINTF is a reimplementation of the standard C library function printf, according to the C99 standard.

**Specifications**:
- Binary name: libmy.a
- Language: C
- Compilation: via a Makefile, including the rules re, clean and fclean

**Constraints**:
- All source files must be included in the delivery, except for unnecessary files (binaries, temporary files, object files, etc.).
- All bonus files (including a specific Makefile) must be placed in a bonus directory.
- Error messages must be written to the error output.
- You must handle all printf flags.
- Internal buffer management of printf is not required.
- LibC forbidden, except for: va_start, va_end, va_arg, malloc, free, write

**Example usage**:
```c
char str[8];
my_strcpy(str, "world!");
my_printf("Hello %s\n", str);
```

---

### Project 3: My_hunter

**Description**: MY_HUNTER is a video game inspired by the famous Duck Hunt. The player is a hunter who needs to shoot moving ducks.

**Features**:
- A window that can be closed with events.
- Mouse input handling (clicks to shoot ducks).
- Use of animated sprites with sprite sheets.
- Presence of moving elements (translation, rotation or scaling).
- Option -h displaying a brief description of the program and available commands.

**Compilation**:
```bash
make        # Compilation
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Full recompilation
```

---

### Project 4: Organized

**Description**: Organized is a C programming project aimed at organizing and sorting materials in a virtual laboratory using linked lists. The goal is to store, delete, display, and sort objects according to defined criteria such as type, name, and ID.

**Features**:
- Commands: `add`, `del`, `disp`, `sort`

**Specifications**:
- Materials are classified into 5 main categories: `Actuators`, `Devices`, `Processors`, `Sensors`, `Wires`.

**Example usage**:
```bash
add WIRE usb, ACTUATOR button
disp
sort NAME -r
disp
```

---

### Project 5: 101PONG

**Description**: 101PONG is a 3D version of the famous Pong game developed by Ralph Baer in 1972. This project focuses solely on simulating the ball's movement, without considering paddle interaction or collision management.

**Features**:
- Calculation of the ball's velocity vector.
- Calculation of the ball's position after a certain time interval.
- Calculation of the ball's angle of incidence with the paddle (if applicable).

**Compilation**:
```bash
make        # Compilation
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Full recompilation
```

---

### Project 6: Popeye

**Description**: POPEYE is a project that will help you master the basics of containerizing applications and defining multi-container infrastructures using Docker and Docker Compose.

**Services**:
1. **Poll (Flask - Python)**
2. **Redis**
3. **Worker (Java)**
4. **PostgreSQL**
5. **Result (Node.js)**

**Docker Configuration**:
- **Poll Dockerfile**: Based on an official Python image.
- **Result Dockerfile**: Based on an official Node.js version 20 Alpine image.
- **Worker Dockerfile**: Uses a multi-stage build.
- **PostgreSQL Dockerfile**: Based on the official PostgreSQL version 16 image.

**Docker Compose**:
- Services: `poll`, `redis`, `worker`, `db`, `result`
- Networks: `poll-tier`, `result-tier`, `back-tier`
- Volume: `db-data`
- Automatic restart

---

## Installation

To clone this repository locally, use the following command:

```bash
git clone https://github.com/nael481/portfolio.git
```

## Contact

For any questions or suggestions, please contact me at the following email address: nael.gamba@epitech.eu