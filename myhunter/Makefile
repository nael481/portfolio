##
## EPITECH PROJECT, 2024
## rush3
## File description:
## rush3
##

NAME = my_hunter

SRC	= my_putchar.c\
	my_putnbr.c\
	my_putstr.c\
	my_revstr.c\
	main.c\
	home_page.c\
	game.c\
	sprite.c\
	home_page_button.c\
	game_over.c\
	song_and_display.c\
	strcat.c\
	int_to_str.c\
	game2.c\
	game3.c\
	home_page2.c\
	sprite2.c\


OBJ = $(SRC:.c=.o)

CSFML = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all : $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) $(CSFML) -lm -g3



clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
