/*
** EPITECH PROJECT, 2025
** Module: String
** File description:
** Implementation for
** string_reserve
*/

#include <project_starter/string.h>
#include <project_starter/memory.h>


/**
 * Reserves capacity bytes
 * in the given string.
 * If the string already has
 * enough space for capacity
 * bytes, this does nothing.
 */
void string_reserve(String *str, size_t capacity)
{
    if (str->capacity >= capacity)
        return;
    str->c_str = xrealloc(str->c_str, capacity);
    str->capacity = capacity;
}
