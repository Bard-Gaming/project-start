/*
** EPITECH PROJECT, 2025
** Project Starter
** File description:
** Program Entry
*/

#include <project_starter/templating.h>
#include <project_starter/hashtable.h>
#include <project_starter/common.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <argp.h>


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
    { "language", 'l', "LANGUAGE", 0, "Choose the project's programming language (default: C)" },
    { "year", 'y', "YEAR", 0, "Set the 'year' variable for templates (default: current year)" },
    { "organisation", 'o', "ORGANISATION", 0, "Set the 'organisation' variable for templates (default: EPITECH)" },
    { 0 }
};

static error_t parse_option(int key, char *arg, struct argp_state *state)
{
    TemplateContext *context = state->input;

    switch (key) {
        case 'o':
            hashtable_set(&context->variables, "organisation", arg);
            return 0;
        case 'l':
            context->language = arg;
            return 0;
        case 'y':
            hashtable_set(&context->variables, "year", arg);
            return 0;

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

    argp_parse(&arg_parser, argc, argv, 0, 0, &context);
    template_register_context_names(&context);

    template_generate(&context);

    hashtable_delete(&context.variables, NULL);
}
