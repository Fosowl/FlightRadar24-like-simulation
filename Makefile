##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

TEST_NAME	=	unit_tests

LIB_NAME	 = libsuper.a

BIN_NAME	= my_radar

IDIR	= include/

LIB_DIR	= lib/

CHAIN_DIR = chain/

SRC_DIR = src/

LIB_FILES	= my_putchar.c\
			  my_put_nbr.c\
			  my_putstr.c\
			  conversion.c\
			  get.c\
			  initialize.c\
			  parsing.c\
			  sort.c\
			  letter.c\
			  print_float.c\
			  replace.c\
			  error.c\
			  light_python.c

CHAIN_FILES	= push.c\
			  pop.c\
			  set.c

SRC_FILES	= main.c\
			  game.c\
			  load_data.c\
			  interface.c\
			  camera.c\
			  load_texture.c\
			  initialize.c\
			  tower.c\
			  aircraft.c\
			  interact.c\
			  measure_distance.c\
			  move_sprite.c\
			  drawing.c\
			  set_data.c\
			  clock.c

TEST	 = tests/test.c

CFLAGS	+= -I $(IDIR) -W -Wall -Wextra -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

LIB		= $(addprefix $(LIB_DIR), $(LIB_FILES))

SRC		= $(addprefix $(SRC_DIR), $(SRC_FILES))

CHAIN	= $(addprefix $(CHAIN_DIR), $(CHAIN_FILES))

OBJS		 = $(LIB:.c=.o)

CHAIN_OBJS	= $(CHAIN:.c=.o)

all: $(LIB_NAME) $(BIN_NAME)

$(LIB_NAME): $(OBJS) $(CHAIN_OBJS)
	@ar rc $(LIB_NAME) $(OBJS) $(CHAIN_OBJS)
	@echo -e "\033[1;32mlibraries compilation complete !"

$(BIN_NAME):
		@gcc -o $(BIN_NAME) $(SRC) $(LIB_NAME) $(CFLAGS) -g3
		@echo -e "\033[1;32mcompilation complete !"

tests_run: fclean all
	@gcc -o $(TEST_NAME) $(TEST) $(LIB_NAME) $(CFLAGS) --coverage -lcriterion
	@echo -e "\033[1;94mtest compilation complete !"
	./$(TEST_NAME)

clean:
	@echo -e "\033[1;33mremoving compilation files !\033[1;36m"
	@rm -f $(OBJS)
	@rm -f $(CHAIN_OBJS)

fclean: clean
	@echo -e "\033[1;33mremoving binary files !\033[1;36m"
	@rm -f $(LIB_NAME)
	@rm -f $(BIN_NAME)

re:	fclean all

.PHONY: all clean fclean re
