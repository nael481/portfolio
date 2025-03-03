##
## EPITECH PROJECT, 2024
## makfile
## File description:
## makfile
##

NAME    =    libmy.a

LMY 	=	 my.h

SRC        = my_printf.c\
			 my_putchar.c\
			 my_hexa_maj.c \
			 my_hexa.c \
			 my_putnbr.c \
			 my_putstr.c\
			 my_strlen.c\
			 octal.c\
			 ecriture_scientifique.c\
			 my_revstr.c\
			 putdouble.c\
			 maj_ecriture_scientifique.c\
			 modulo_p.c\
			 my_putfloat.c\


OBJ        =    $(SRC:.c=.o)

all:    $(OBJ)
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ)
	rm -f $(NAME)

re: fclean all
