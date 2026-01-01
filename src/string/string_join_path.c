/*
** EPITECH PROJECT, 2025
** Module: String
** File description:
** Implementation for
** string_join_path
*/

#include <project_starter/string.h>
#include <stdbool.h>


/**
 * Determines if a delimiter ('/')
 * needs to be added between the
 * two path strings.
 */
static bool needs_delimiter(String *path_start, const char *path_end)
{
    return
        (path_end[0] != '/') &&
        (path_start->length > 0) &&
        (path_start->c_str[path_start->length - 1] != '/');
}

/**
 * Joins two paths together, adding
 * a '/' in-between the strings if
 * necessary.
 */
void string_join_path(String *path_start, const char *path_end)
{
    if (needs_delimiter(path_start, path_end)) {
        string_addchr(path_start, '/');
    }

    string_addstr(path_start, path_end);
}
