##
## EPITECH PROJECT, 2025
## Project Starter
## File description:
## Project Makefile
##

NAME = project-start

CONFIG_PATH = $(HOME)/.config/project-start/
TEMPLATES_DIR = templates/
USR_BIN = ~/.local/bin/

INCLUDE_DIRS = -I./include/

CFLAGS += -D'PROJECT_STARTER_CONFIG_PATH="$(CONFIG_PATH)"'

SRC_FILES =	\
			src/hashtable/hashtable_delete.c						\
			src/hashtable/hashtable_get.c							\
			src/hashtable/hashtable_get_bucket.c					\
			src/hashtable/hashtable_hash.c							\
			src/hashtable/hashtable_init.c							\
			src/hashtable/hashtable_set.c							\
			src/memory/xcalloc.c									\
			src/memory/xmalloc.c									\
			src/string/string_addchr.c								\
			src/string/string_addmem.c								\
			src/string/string_addstr.c								\
			src/string/string_copy.c								\
			src/string/string_delete.c								\
			src/string/string_from_reference.c						\
			src/string/string_new.c									\
			src/string/string_reserve.c								\
			src/templating/template_create_context.c				\
			src/templating/template_generate.c						\
			src/templating/template_generate_file.c					\
			src/templating/template_generate_from_directory.c		\
			src/templating/template_parse_content.c					\
			src/templating/template_register_context_names.c		\
			src/main.c												\

OBJ_FILES = $(SRC_FILES:.c=.o)

.PHONY: all install debug sanitize clean fclean re

all: $(NAME)

install: CFLAGS += -Ofast
install: $(NAME) $(TEMPLATES_DIR)
	@if ! [[ -d ~ ]]; then 															\
		printf "\033[31m%s\033[0m\n" "unable to install: no home directory" >&2;	\
		false; 																		\
	fi
	@printf "%s\n" "creating directory $(CONFIG_PATH)"
	@mkdir --parents $(CONFIG_PATH)

	@printf "%s\n" "copying templates into config"
	@cp -r $(TEMPLATES_DIR) $(CONFIG_PATH)

	@printf "%s\n" "adding binary to $(USR_BIN)"
	@cp $(NAME) $(USR_BIN)

	@printf "\033[32m%s\033[0m\n" "successfully installed $(NAME)"

%.o: %.c
	@$(CC) -c $< $(INCLUDE_DIRS) $(CFLAGS) -o $@
	@printf "%s\n" 'cc -c $<'

$(NAME): $(OBJ_FILES)
	@$(CC) $(OBJ_FILES) $(INCLUDE_DIRS) $(CFLAGS) -o $(NAME)
	@printf "%s\n" 'cc -o $@'

debug: CFLAGS += -ggdb
debug: fclean $(NAME)

sanitize: CFLAGS += -g -fsanitize=address -lasan
sanitize: fclean $(NAME)

clean:
	@rm -f $(OBJ_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all
