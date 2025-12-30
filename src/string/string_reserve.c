/*
** EPITECH PROJECT, 2025
** Module: String
** File description:
** Implementation for
** string_reserve
*/

#include <project_starter/string.h>
#include <stdlib.h>
#include <stdio.h>


/**
 * Attempts to reallocate memory,
 * ending the program on failure.
 */
static void *xrealloc(void *ptr, size_t size)
{
    void *res = realloc(ptr, size);

    if (size != 0 && res == NULL) {
        fputs("critical error: not enough memory to reallocate data\n", stderr);
        exit(127);
    }
    return res;
}


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
