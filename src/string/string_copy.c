/*
** EPITECH PROJECT, 2025
** Module: String
** File description:
** Implementation for
** string_copy
*/

#include <project_starter/string.h>
#include <project_starter/memory.h>
#include <string.h>


/**
 * Duplicates a string into
 * a new, independent copy.
 */
String string_copy(const String *str)
{
    // Don't use strdup since we already know length
    char *copy = xmalloc((str->length + 1) * sizeof(char));
    memcpy(copy, str->c_str, str->length + 1);

    return (String){
        .capacity = str->length + 1,
        .length= str->length,
        .c_str = copy,
    };
}
