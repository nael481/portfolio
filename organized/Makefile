##
## EPITECH PROJECT, 2024
## organized
## File description:
## organized
##

NAME = organized

SRC	= main.c\
	add.c\
	disp.c\
	sort.c\
	del.c\
	mini_printf.c\
	my_putchar.c\
	my_putnbr.c\
	my_putstr.c\
	my_revstr.c\
	my_strcmp.c\
	my_strdup.c\
	my_strlen.c\
	int_to_str.c\
	del2.c\
	sort2.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -lshell -L./ -g3

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
