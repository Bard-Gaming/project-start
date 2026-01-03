/*
** EPITECH PROJECT, 2025
** Module: Memory
** File description:
** Implementation for
** xreallocarray
*/
#include <project_starter/memory.h>
#include <stdlib.h>
#include <stdio.h>


/**
 * Attempts to reallocate memory,
 * ending the program on failure.
 */
void *xreallocarray(void *ptr, size_t nmemb, size_t size)
{
    void *res = reallocarray(ptr, nmemb, size);

    if (PS_UNLIKELY(size != 0 && res == NULL)) {
        fputs("critical error: failed to reallocate memory array", stderr);
        exit(PS_MEM_ERROR);
    }
    return res;
}
