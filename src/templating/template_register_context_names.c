/*
** EPITECH PROJECT, 2025
** Module: Templating
** File description:
** Implementation for
** template_register_context_names
*/

#include <project_starter/templating.h>
#include <project_starter/string.h>
#include <string.h>


/**
 * Determines if the specified
 * character is legal for project
 * names.
 */
static bool is_legal_char(char c)
{
    return
        ('a' <= c && c <= 'z') ||
        ('A' <= c && c <= 'Z') ||
        ('0' <= c && c <= '9') ||
        (c == '-') ||
        (c == '_');
}

/**
 * Determines if the given name
 * constitutes a legal project
 * name or not.
 */
static bool is_legal_name(const char *name)
{
    for (size_t i = 0; name[i] != '\0'; i++) {
        if (is_legal_char(name[i]))
            continue;
        return false;
    }

    return true;
}

/**
 * Registers the available names in
 * the template context's variables.
 *
 * Returns true on success and false
 * if the specified project name is
 * illegal.
 */
bool template_register_context_names(TemplateContext *context)
{
    if (context->names[0] == NULL || !is_legal_name(context->names[0]))
        return false;

    if (context->names[1] == NULL)
        context->names[1] = context->names[0];

    hashtable_set(&context->variables, "name", strdup(context->names[0]));
    hashtable_set(&context->variables, "display_name", strdup(context->names[1]));
    return true;
}
