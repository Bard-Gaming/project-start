/*
** EPITECH PROJECT, 2025
** Module: Memory
** File description:
** Implementation for
** xcalloc
*/

#include <project_starter/memory.h>
#include <stdio.h>


/**
 * Allocates memory, crashing
 * the program if not enough
 * memory is available.
 */
void *xcalloc(size_t nmemb, size_t size)
{
    void *ptr = calloc(nmemb, size);

    if (PS_UNLIKELY(ptr == NULL)) {
        fputs("critical error: failed to allocate memory", stderr);
        exit(PS_MEM_ERROR);
    }
    return ptr;
}
