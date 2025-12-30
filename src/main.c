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


static const char doc[] =
    "Start working on projects - the fast way.\n"
    "Example: project-start cool_project";


static struct argp arg_parser = {
    .doc = doc,
};


int main(int argc, char *argv[])
{
    argp_parse(&arg_parser, argc, argv, 0, 0, 0);
}


#if 0
int main(int argc, char *argv[])
{
    TemplateContext context = template_create_context();

    hashtable_set(&context.variables, "name", "test");
    hashtable_set(&context.variables, "display_name", "Test Project");
    hashtable_set(&context.variables, "project_org", "EPITECH");
    hashtable_set(&context.variables, "year", "2025");

    template_generate(&context);

    hashtable_delete(&context.variables, NULL);
}
#endif
