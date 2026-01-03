/*
** EPITECH PROJECT, 2025
** Module: Templating
** File description:
** Implementation for
** template_get_available_langs
*/

#include <project_starter/templating.h>
#include <project_starter/vector.h>
#include <string.h>
#include <dirent.h>


/**
 * Returns a vector containing the names
 * of the available programming languages,
 * as defined in the template config.
 */
Vector template_get_available_langs(const char *dir_path)
{
    Vector vec = { 0 };
    DIR *dir = opendir(dir_path);
    if (dir == NULL)
        return vec;

    struct dirent *entry = readdir(dir);
    while (entry != NULL) {
        vector_push_back(&vec, strdup(entry->d_name));
        entry = readdir(dir);
    }

    closedir(dir);
    return vec;
}
