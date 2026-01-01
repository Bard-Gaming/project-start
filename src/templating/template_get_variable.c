/*
** EPITECH PROJECT, 2025
** Module: Templating
** File description:
** Implementation for
** template_get_variable
*/

#include <project_starter/templating.h>
#include <project_starter/string.h>


/**
 * Determines if a string is uppercase
 * or not.
 */
static bool is_uppercase(const char *str)
{
    for (size_t i = 0; str[i] != '\0'; i++) {
        if ('a' <= str[i] && str[i] <= 'z')
            return false;
    }
    return true;
}

/**
 *
 */
static char *get_uppercase_value(Hashtable *vars, const char *key)
{
    String lowercase_key = string_from_reference(key);
    string_lower(&lowercase_key);

    char *lowercase_value = hashtable_get(vars, lowercase_key.c_str);
    string_delete(&lowercase_key);

    if (lowercase_value == NULL)
        return NULL;

    String uppercase_value = string_from_reference(lowercase_value);
    string_upper(&uppercase_value);

    // Cache result to allow cleaning up later (+ for speed)
    hashtable_set(vars, key, uppercase_value.c_str);

    return uppercase_value.c_str;
}

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

    if (value == NULL && is_uppercase(key))
        // FIXME: const qualifier discard cast below
        return get_uppercase_value((Hashtable *)&context->variables, key);

    return value;
}
