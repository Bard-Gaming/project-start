/*
** EPITECH PROJECT, 2025
** Module: OS
** File description:
** Implementation for
** os_move
*/

#include <project_starter/os.h>
#include <stddef.h>


/**
 * Small utility function to make moving
 * files / directories easier.
 *
 * Depends on coreutil's `mv` command.
 */
int os_move(const char *src_path, const char *dest_path)
{
    const char *command[] = { "mv", src_path, dest_path, NULL };

    return os_exec_command(command);
}
