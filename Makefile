##
## EPITECH PROJECT, 2025
## Project Starter
## File description:
## Project Makefile
##

NAME = project-start

INCLUDE_DIRS = -I./include/

SRC_FILES =	src/string/string_addchr.c					\
			src/string/string_addmem.c					\
			src/string/string_addstr.c					\
			src/string/string_delete.c					\
			src/string/string_from_reference.c			\
			src/string/string_new.c						\
			src/string/string_reserve.c					\
			src/templating/template_parse_stream.c		\
			src/main.c									\

OBJ_FILES = $(SRC_FILES:.c=.o)

.PHONY: all debug clean fclean re

all: $(NAME)

%.o: %.c
	@$(CC) -c $< $(INCLUDE_DIRS) $(CFLAGS) -o $@
	@echo 'cc -c $<'

$(NAME): $(OBJ_FILES)
	@$(CC) $(OBJ_FILES) $(INCLUDE_DIRS) $(CFLAGS) -o $(NAME)
	@echo 'cc -o $@'

debug: CFLAGS += -ggdb
debug: $(NAME)

clean:
	@rm -f $(OBJ_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all
