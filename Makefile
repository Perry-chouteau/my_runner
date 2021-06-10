##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

SRC =	sources/my_atof.c	\
\
		sources/window.c	\
\
		sources/set_map.c	\
		sources/init1.c	\
		sources/init2.c	\
		sources/func_base.c	\
\
		sources/event.c	\
		sources/sprite.c	\
\
		sources/changes.c	\
		sources/change_pos.c	\
		sources/change_pos2.c	\
		sources/change_rect.c	\
		sources/change_txt.c	\
\
		sources/lobby.c	\
		sources/my_pause.c	\
		sources/lose.c	\
		sources/win.c	\
\
		sources/destruct.c

OBJ = $(SRC:.c=.o)

NAME = my_runner

SVFL = *~

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -l csfml-graphics -l csfml-audio -l csfml-window -l csfml-system -Wall -Wextra -g3

clean:
	rm -rf $(SVFL)

fclean: clean
	rm -rf $(OBJ)
	rm -rf $(NAME)

re: fclean all

launch: re
	./$(NAME) file.txt 3 0.0001

lvl1: re
	./$(NAME) lvl/lvl1.txt 1 0.0001

lvl2: re
	./$(NAME) lvl/lvl2.txt 2 0.0001

lvl3: re
	./$(NAME) lvl/lvl3.txt 1 0.001

lvl4: re
	./$(NAME) lvl/lvl4.txt 4 0.0001

lvl5: re
	./$(NAME) lvl/lvl5.txt 0.4

.PHONY: all clean fclean re launch lvl1 lvl2 lvl3 lvl4 lvl5
