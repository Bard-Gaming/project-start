##
## EPITECH PROJECT, 2025
## Project Starter
## File description:
## Project Makefile
##

NAME = project-start

PROJECT_CONFIG_FILES = config/templates/ config/variables.cfg
USR_CONFIG_DIR = $(HOME)/.config/project-start/
USR_BIN = /usr/bin

INCLUDE_DIRS = -I./include/

CFLAGS += -D'PROJECT_STARTER_CONFIG_PATH="$(USR_CONFIG_DIR)"'

SRC_FILES =	\
			src/config/config_load_variables.c						\
			src/config/config_parse_value.c							\
			src/hashtable/hashtable_delete.c						\
			src/hashtable/hashtable_get.c							\
			src/hashtable/hashtable_get_bucket.c					\
			src/hashtable/hashtable_hash.c							\
			src/hashtable/hashtable_init.c							\
			src/hashtable/hashtable_set.c							\
			src/memory/xcalloc.c									\
			src/memory/xmalloc.c									\
			src/memory/xrealloc.c									\
			src/memory/xreallocarray.c								\
			src/os/os_exec_command.c								\
			src/os/os_is_empty_directory.c							\
			src/os/os_move.c										\
			src/os/os_path_exists.c									\
			src/os/os_readable_time.c								\
			src/string/string_addchr.c								\
			src/string/string_addmem.c								\
			src/string/string_addstr.c								\
			src/string/string_clear.c								\
			src/string/string_copy.c								\
			src/string/string_delete.c								\
			src/string/string_from_reference.c						\
			src/string/string_join_path.c							\
			src/string/string_lower.c								\
			src/string/string_new.c									\
			src/string/string_reserve.c								\
			src/string/string_upper.c								\
			src/templating/template_create_context.c				\
			src/templating/template_delete_context.c				\
			src/templating/template_generate.c						\
			src/templating/template_generate_file.c					\
			src/templating/template_generate_from_directory.c		\
			src/templating/template_generate_git.c					\
			src/templating/template_get_available_langs.c			\
			src/templating/template_get_variable.c					\
			src/templating/template_is_available_lang.c				\
			src/templating/template_parse_content.c					\
			src/templating/template_register_context_names.c		\
			src/vector/vector_contains.c							\
			src/vector/vector_delete.c								\
			src/vector/vector_grow.c								\
			src/vector/vector_push_back.c							\
			src/vector/vector_remove_fast.c							\
			src/vector/vector_reserve.c								\
			src/main.c												\

OBJ_FILES = $(SRC_FILES:.c=.o)

.PHONY: all install debug sanitize clean fclean re

all: $(NAME)

$(USR_CONFIG_DIR):
	@if ! [[ -d ~ ]]; then															\
		printf "\033[31m%s\033[0m\n" "unable to install: no home directory" >&2;	\
		false; 																		\
	fi

	@printf "%s\n" "creating directory $(USR_CONFIG_DIR)"
	@mkdir --parents $(USR_CONFIG_DIR)

install: CFLAGS += -Ofast
install: $(NAME) $(PROJECT_CONFIG_FILES) $(USR_CONFIG_DIR)
	@printf "%s\n" "copying templates into config"
	@cp -r $(PROJECT_CONFIG_FILES) $(USR_CONFIG_DIR)

	@printf "%s\n" "adding binary to $(USR_BIN)"
	@sudo cp $(NAME) $(USR_BIN)

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
