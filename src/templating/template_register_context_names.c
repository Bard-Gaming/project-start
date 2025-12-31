/*
** EPITECH PROJECT, 2025
** Module: Templating
** File description:
** Implementation for
** template_register_context_names
*/

#include <project_starter/templating.h>


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
    hashtable_set(&context->variables, "display_name", (void *)context->names[1]);
}
