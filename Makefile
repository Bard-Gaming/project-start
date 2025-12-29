##
## EPITECH PROJECT, 2025
## Project Starter
## File description:
## Project Makefile
##

NAME = project-start

INCLUDE_DIRS = -I./include/

SRC_FILES =	src/main.c		\

OBJ_FILES = $(SRC_FILES:.c=.o)

.PHONY: all debug clean fclean re

all: $(NAME)

%.o: %.c
	$(CC) -c $< $(INCLUDE_DIRS) $(CFLAGS) -o $@

$(NAME): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) $(INCLUDE_DIRS) $(CFLAGS) -o $(NAME)

debug: CFLAGS += -ggdb
debug: $(NAME)

clean:
	@rm -f $(OBJ_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all
