/*
** EPITECH PROJECT, 2025
** Module: String
** File description:
** Implementation for
** string_addmem
*/

#include <project_starter/string.h>
#include <string.h>


/**
 * Grows the given string until it is
 * large enough to be able to hold the
 * specified extra size.
 */
static void grow_string(String *str, size_t extra_size)
{
    size_t required_size = str->capacity + extra_size;
    size_t new_capacity = str->capacity == 0
        ? STRING_START_CAPACITY
        : str->capacity * STRING_GROWTH;

    while (new_capacity < required_size) {
        new_capacity *= STRING_GROWTH;
    }
    string_reserve(str, new_capacity);
}

/**
 * Adds the given reference memory
 * to the end of the string, increasing
 * the string's capacity if required.
 */
void string_addmem(String *str, const char *restrict mem, size_t size)
{
    if (size == 0)
        return;
    if (str->length + size + 1 > str->capacity)
        grow_string(str, size);
    memcpy(str->c_str + str->length, mem, size);
    str->length += size;
    str->c_str[str->length] = '\0';
}
