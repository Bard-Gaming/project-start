/*
** EPITECH PROJECT, 2025
** Module: String
** File description:
** Implementation for
** string_lower
*/

#include <project_starter/string.h>
#include <stdbool.h>


/**
 * Returns true if the given char
 * is an uppercase alphabetical
 * character.
 */
static bool is_uppercase_alpha(char c)
{
    return 'A' <= c && c <= 'Z';
}

/**
 * Turns all uppercase alphabetical
 * characters into lowercase alphabetical
 * characters.
 */
void string_lower(String *str)
{
    const char offset = 'A' - 'a';

    for (size_t i = 0; i < str->length; i++) {
        if (!is_uppercase_alpha(str->c_str[i]))
            continue;

        str->c_str[i] -= offset;
    }
}
