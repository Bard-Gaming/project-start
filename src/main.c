/*
** EPITECH PROJECT, 2025
** Project Starter
** File description:
** Program Entry
*/

#include <project_starter.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <argp.h>

#define OPT_LIST_KEY 1


const char *argp_program_version =
    "project-start " PROJECT_STARTER_VERSION "\n"
    "License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\n"
    "This is free software: you are free to change and redistribute it.\n"
    "There is NO WARRANTY, to the extent permitted by law.\n"
    "\n"
    "Written by Bard-Gaming on GitHub; see\n"
    "<https://github.com/Bard-Gaming/>.";

const char *argp_program_bug_address =
    "<https://github.com/Bard-Gaming/project-start/issues/new>";

static const char doc[] =
    "Start working on projects - the fast way.\n"
    "Example: project-start cool_project";


static const char args_doc[] = "NAME [DISPLAY_NAME]";

static const struct argp_option options[] = {
    { "list", OPT_LIST_KEY, NULL, 0, "Display available languages and exit" },
    { "git", 'g', NULL, 0, "Initialize a new git repository;\nIf a remote is specified, this is implicitly true." },
    { "language", 'l', "LANGUAGE", 0, "Choose the project's programming language (default: C)" },
    { "remote", 'r', "REMOTE_URL", 0, "Specify a git remote url for the project" },
    { 0 }
};

__attribute__((noreturn)) static void list_available_langs(void)
{
    String template_dir_path = string_from_reference(PROJECT_STARTER_CONFIG_PATH);
    string_join_path(&template_dir_path, "templates");

    Vector available_langs = template_get_available_langs(template_dir_path.c_str);
    string_delete(&template_dir_path);

    puts("Available programming languages are:");
    for (size_t i = 0; i < available_langs.count; i++) {
        puts(available_langs.data[i]);
    }
    vector_delete(&available_langs, vector_free_item);

    exit(0);
}

__attribute__((noreturn)) static void illegal_project_name_error(const char *name)
{
    fprintf(
        stderr,
        "critical error: name \"%s\" is not a legal project name\n",
        name
    );
    exit(2);
}

__attribute__((noreturn)) static void lang_not_available_error(const char *str)
{
    fprintf(
        stderr,
        "critical error: language \"%s\" is not available.\n"
        "Please choose from an available language, "
        "or update your configuration.\n",
        str
    );
    exit(2);
}

static error_t parse_option(int key, char *arg, struct argp_state *state)
{
    TemplateContext *context = state->input;

    switch (key) {
        case 'g':
            context->should_initialize_git = true;
            return 0;
        case 'l':
            context->language = arg;
            return 0;
        case 'r':
            context->git_remote = arg;
            context->should_initialize_git = true;
            return 0;
        case OPT_LIST_KEY:
            list_available_langs();

        case ARGP_KEY_ARG:
            if (context->names[1] != NULL)
                argp_usage(state);

            unsigned int index = context->names[0] == NULL ? 0 : 1;
            context->names[index] = arg;
            return 0;

        case ARGP_KEY_END:
            if (context->names[0] == NULL)
                argp_usage(state);
            return 0;

        default:
            return ARGP_ERR_UNKNOWN;
    }
}

static struct argp arg_parser = {
    .doc = doc,
    .args_doc = args_doc,
    .options = options,
    .parser = parse_option,
};

int main(int argc, char *argv[])
{
    TemplateContext context = template_create_context();
    bool success;

    argp_parse(&arg_parser, argc, argv, 0, 0, &context);
    if (!template_is_available_lang(context.language)) {
        lang_not_available_error(context.language);
    }

    success = template_register_context_names(&context);
    if (!success)
        illegal_project_name_error(context.names[0]);

    success = template_generate(&context);

    template_delete_context(&context);

    return success ? 0 : 1;
}
