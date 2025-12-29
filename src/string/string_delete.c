/*
** EPITECH PROJECT, 2025
** Module: String
** File description:
** Implementation for
** string_delete
*/

#include <project_starter/string.h>
#include <stdlib.h>


/**
 * Deletes the contents
 * of the given string.
 */
void string_delete(String *str)
{
    free(str->c_str);
    str->c_str = NULL;
    str->capacity = 0;
    str->length = 0;
}
