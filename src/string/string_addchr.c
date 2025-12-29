/*
** EPITECH PROJECT, 2025
** Module: String
** File description:
** Implementation for
** string_addchr
*/

#include <project_starter/string.h>


/**
 * Grows the given string by the
 * defined growth factor, if applicable.
 */
static void grow_string(String *str)
{
    size_t new_capacity = str->capacity < 2
        ? STRING_START_CAPACITY
        : str->capacity * STRING_GROWTH;

    string_reserve(str, new_capacity);
}

/**
 * Adds a given character to
 * the string, increasing its
 * capacity if required.
 */
void string_addchr(String *str, char c)
{
    if (str->length + 2 > str->capacity)
        grow_string(str);
    str->c_str[str->length] = c;
    str->length++;
    str->c_str[str->length] = '\0';
}
