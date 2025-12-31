/*
** EPITECH PROJECT, 2025
** Module: String
** File description:
** Implementation for
** string_upper
*/

#include <project_starter/string.h>
#include <stdbool.h>


/**
 * Returns true if the given char
 * is a lowercase alphabetical
 * character.
 */
static bool is_lowercase_alpha(char c)
{
    return 'a' <= c && c <= 'z';
}

/**
 * Turns all lowercase alphabetical
 * characters into uppercase alphabetical
 * characters.
 */
void string_upper(String *str)
{
    const char offset = 'A' - 'a';

    for (size_t i = 0; i < str->length; i++) {
        if (!is_lowercase_alpha(str->c_str[i]))
            continue;

        str->c_str[i] += offset;
    }
}
