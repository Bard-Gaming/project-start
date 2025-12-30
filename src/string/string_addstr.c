/*
** EPITECH PROJECT, 2025
** Module: String
** File description:
** Implementation for
** string_addstr
*/

#include <project_starter/string.h>
#include <string.h>


/**
 * Adds the given reference string
 * to the end of the string, increasing
 * the string's capacity if required.
 */
void string_addstr(String *str, const char *restrict ref)
{
    return string_addmem(str, ref, strlen(ref));
}
