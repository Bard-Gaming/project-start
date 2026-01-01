/*
** EPITECH PROJECT, 2025
** Module: Templating
** File description:
** Implementation for
** template_get_variable
*/

#include <project_starter/templating.h>


/**
 * Retrieves a saved variable within
 * the given context (if present).
 *
 * If no value is associated with the
 * given key, NULL is returned instead.
 *
 * Note:
 * This function is preferred over using
 * hashtable_get(), as it includes some
 * additional utilities (such as automatic
 * upper case).
 */
char *template_get_variable(const TemplateContext *context, const char *key)
{
    char *value = hashtable_get(&context->variables, key);

    return value;
}
