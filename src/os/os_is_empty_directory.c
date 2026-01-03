/*
** EPITECH PROJECT, 2025
** Module: OS
** File description:
** Implementation for
** os_is_empty_directory
*/

#include <project_starter/os.h>
#include <string.h>
#include <dirent.h>


/**
 * Returns true if name is "." or "..",
 * else false.
 */
static bool is_ignored(const char *name)
{
    return name[0] == '.'
        ? name[1] == '\0' || strcmp(name + 1, ".")
        : false;
}

/**
 * Determines if the given path
 * points to nothing or an empty
 * directory.
 */
bool os_is_empty_directory(const char *path)
{
    DIR *directory = opendir(path);
    if (directory == NULL)
        return true;

    struct dirent *entry = readdir(directory);
    while (entry != NULL) {
        if (!is_ignored(entry->d_name)) {
            closedir(directory);
            return false;
        }

        entry = readdir(directory);
    }

    closedir(directory);
    return true;
}
