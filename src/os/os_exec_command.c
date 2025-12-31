/*
** EPITECH PROJECT, 2025
** Module: OS
** File description:
** Implementation for
** os_exec_git_cmd
*/

#include <project_starter/os.h>
#include <project_starter/memory.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>


static size_t array_length(const char *argv[])
{
    size_t length;

    for (length = 0; argv[length] != NULL; length++);
    return length;
}

static char **duplicate_array(const char *ref[])
{
    size_t len = array_length(ref);
    char **duplicate = xmalloc((len + 1) * sizeof(char *));

    for (size_t i = 0; i < len; i++)
        duplicate[i] = strdup(ref[i]);
    duplicate[len] = NULL;

    return duplicate;
}

static void free_array(char *array[])
{
    for (size_t i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}

static void child_process(const char *argv[])
{
    char **argv_copy = duplicate_array(argv);

    execvp(argv[0], argv_copy);

    free_array(argv_copy);
    exit(1);  // in case execvp fails
}

/**
 * Note: the last given argument
 * MUST imperatively be NULL.
 */
int os_exec_command(const char *argv[])
{
    pid_t child_proc = fork();
    if (child_proc == -1) {
        fputs("error: failed to fork\n", stderr);
        return 127;
    }

    if (child_proc == 0) {
        child_process(argv);
    }

    int stat_loc = 0;
    waitpid(child_proc, &stat_loc, 0);

    return WIFEXITED(stat_loc)
        ? WEXITSTATUS(stat_loc)
        : 127;
}
