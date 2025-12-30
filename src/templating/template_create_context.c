/*
** EPITECH PROJECT, 2025
** Module: Templating
** File description:
** Implementation for
** template_create_context
*/

#include <project_starter/templating.h>
#include <project_starter/hashtable.h>


/**
 * Creates a template context with
 * default values.
 */
TemplateContext template_create_context(void)
{
    TemplateContext context = {
        .language = "C",
        .variables = { 0 },
    };

    hashtable_init(&context.variables);
    return context;
}
