/*
** EPITECH PROJECT, 2025
** Module: Hashtable
** File description:
** Implementation for
** xmalloc
*/

#include <project_starter/memory.h>
#include <stdio.h>


/**
 * Allocates memory, crashing
 * the program if not enough
 * memory is available.
 */
void *xmalloc(size_t size)
{
    void *ptr = malloc(size);

    if (PS_UNLIKELY(ptr == NULL)) {
        fputs("critical error: failed to allocate memory", stderr);
        exit(PS_MEM_ERROR);
    }
    return ptr;
}
