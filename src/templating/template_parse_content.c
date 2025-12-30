/*
** EPITECH PROJECT, 2025
** Module: Templating
** File description:
** Implementation for
** template_parse_content
*/

#include <project_starter/templating.h>
#include <project_starter/string.h>
#include <stdlib.h>
#include <string.h>


/**
 * Parses the variable at the start
 * of the source ptr and returns it.
 */
static const char *parse_variable(const Hashtable *variables, const char **src)
{
    if ((*src)[0] != '{' || (*src)[1] != '{') {
        (*src)++;
        return "{";
    }
    *src += 2;

    const char *name = *src;
    size_t name_len;

    for (name_len = 0; name[name_len] != '\0' && name[name_len] != '}'; name_len++);

    if (name[name_len] == '\0' || name[name_len + 1] != '}') {
        return "{{";
    }

    char *name_cpy = strndup(name, name_len + 1);
    name_cpy[name_len] = '\0';

    const char *value = hashtable_get(variables, name_cpy);
    if (value == NULL) {
        fprintf(stderr, "warning: use of undefined variable \"%s\"\n", name_cpy);
        free(name_cpy);
        return "{{";
    }

    free(name_cpy);
    *src += name_len + 2;
    return value;
}

/**
 * Parses the given content, replacing
 * all variables by their values, as
 * defined in the variables table.
 */
char *template_parse_content(const Hashtable *variables, const char *src)
{
    String result = { 0 };
    string_reserve(&result, strlen(src) + 1);

    while (*src != '\0') {
        if (*src == '{') {
            const char *content = parse_variable(variables, &src);
            string_addstr(&result, content);
            continue;
        }

        string_addchr(&result, *src);
        src++;
    }

    return result.c_str;
}
