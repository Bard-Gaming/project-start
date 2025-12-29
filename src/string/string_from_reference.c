/*
** EPITECH PROJECT, 2025
** Module: String
** File description:
** Implementation for
** string_from_reference
*/

#include <project_starter/string.h>
#include <string.h>


/**
 * Similar to string_new(), except
 * that it duplicates the argument,
 * leaving it untouched.
 */
String string_from_reference(const char *ref)
{
    return string_new(strdup(ref));
}
