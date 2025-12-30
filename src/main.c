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
