##
## EPITECH PROJECT, 2024
## organized
## File description:
## organized
##

NAME = mysh

SRC	= main.c\
	source.c\
	my_strlen.c\
	my_getenv.c\
	my_strncomp.c\
	abs_command.c\
	ex_command.c\
	use_path.c\
	cd.c\
	prompt.c\
	free.c\
	command.c\
	my_strchr.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -g3

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
