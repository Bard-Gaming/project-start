/*
** EPITECH PROJECT, 2025
** Module: String
** File description:
** Implementation for
** string_new
*/

#include <project_starter/string.h>
#include <string.h>


/**
 * Creates a string with the given
 * character buffer.
 */
String string_new(char *str)
{
    size_t length = strlen(str);

    return (String){
        .c_str = str,
        .length = length,
        .capacity = length + 1,
    };
}
