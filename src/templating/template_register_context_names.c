/*
** EPITECH PROJECT, 2025
** Module: Templating
** File description:
** Implementation for
** template_register_context_names
*/

#include <project_starter/templating.h>
#include <project_starter/string.h>


/**
 * Returns a duplicate of the name
 * in uppercase.
 */
static char *get_uppercase_name(const TemplateContext *context)
{
    String name = string_from_reference(context->names[0]);

    string_upper(&name);
    return name.c_str;
}

/**
 * Registers the available names in
 * the template context's variables.
 */
void template_register_context_names(TemplateContext *context)
{
    if (context->names[0] == NULL)
        return;

    if (context->names[1] == NULL)
        context->names[1] = context->names[0];

    hashtable_set(&context->variables, "name", (void *)context->names[0]);
    hashtable_set(&context->variables, "NAME", get_uppercase_name(context));
    hashtable_set(&context->variables, "display_name", (void *)context->names[1]);
}
