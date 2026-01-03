/*
** EPITECH PROJECT, 2025
** Module: OS
** File description:
** Implementation for
** os_path_exists
*/

#include <project_starter/os.h>
#include <sys/stat.h>


/**
 * Checks if a path exists and
 * is accessible (i.e. if its permissions
 * allow it to be accessed and no errors
 * occur).
 */
bool os_path_exists(const char *path)
{
    struct stat buf;

    return lstat(path, &buf) == 0;
}
