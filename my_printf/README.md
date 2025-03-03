# My_printf

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