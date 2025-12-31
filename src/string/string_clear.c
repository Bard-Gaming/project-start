/*
** EPITECH PROJECT, 2025
** Module: String
** File description:
** Implementation for
** string_clear
*/

#include <project_starter/string.h>


/**
 * Empties the given string
 * without freeing any memory.
 */
void string_clear(String *str)
{
    if (str->capacity == 0)
        return;

    str->c_str[0] = '\0';
    str->length = 0;
}
