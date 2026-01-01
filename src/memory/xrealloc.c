/*
** EPITECH PROJECT, 2025
** Module: Memory
** File description:
** Implementation for
** xrealloc
*/

#include <project_starter/memory.h>
#include <stdlib.h>
#include <stdio.h>


/**
 * Attempts to reallocate memory,
 * ending the program on failure.
 */
void *xrealloc(void *ptr, size_t size)
{
    void *res = realloc(ptr, size);

    if (PS_UNLIKELY(size != 0 && res == NULL)) {
        fputs("critical error: failed to allocate memory", stderr);
        exit(PS_MEM_ERROR);
    }
    return res;
}
