/*
** EPITECH PROJECT, 2025
** Module: Templating
** File description:
** Implementation for
** template_generate_from_directory
*/

#include <project_starter/templating.h>
#include <project_starter/string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>


static bool is_ignored_path(const char *path)
{
    if (path[0] != '.')
        return false;

    if (path[1] == '\0')
        return true;

    return path[1] == '.' && path[2] == '\0';
}

static char *join_paths(const char *a, const char *b)
{
    String result = string_from_reference(a);

    // add delimiter if required
    if (result.c_str[result.length - 1] != '/')
        string_addchr(&result, '/');

    string_addstr(&result, b);

    return result.c_str;
}

/**
 * As the name implies, this function
 * handles the generation of a single
 * directory entry.
 */
static void handle_directory_entry(const Hashtable *vars, struct dirent *entry, const char *dir, const char *dest)
{
    char *entry_path = join_paths(dir, entry->d_name);

    if (entry->d_type == DT_DIR) {
        char *new_destination = join_paths(dest, entry->d_name);

        mkdir(new_destination, 0755);
        template_generate_from_directory(vars, entry_path, new_destination);

        free(new_destination);
    } else {
        template_generate_file(vars, entry_path, dest);
    }

    free(entry_path);
}

/**
 * Generates files from templates
 * located in a directory.
 */
bool template_generate_from_directory(const Hashtable *vars, const char *dir_path, const char *dest_dir)
{
    DIR *directory = opendir(dir_path);
    if (directory == NULL)
        return false;

    struct dirent *entry = readdir(directory);
    while (entry != NULL) {
        if (is_ignored_path(entry->d_name)) {
            entry = readdir(directory);
            continue;
        }

        handle_directory_entry(vars, entry, dir_path, dest_dir);
        entry = readdir(directory);
    }

    closedir(directory);
    return true;
}
