/*
** EPITECH PROJECT, 2025
** Module: Hashtable
** File description:
** Implementation for
** hashtable_init
*/

#include <project_starter/hashtable.h>
#include <stdlib.h>
#include <stdio.h>


static void *xmalloc(size_t size)
{
    void *ptr = malloc(size);

    if (size != 0 && ptr == NULL) {
        fputs("critical error: unable to allocate memory for hashtable", stderr);
        exit(127);
    }
    return ptr;
}

/**
 * Initializes a hashtable.
 * This is required to use operations
 * on the hashtable.
 */
void hashtable_init(Hashtable *table)
{
    table->buckets = xmalloc(
        (1UL << HASHTABLE_INIT_POWER) * sizeof(HashtableBucket *)
    );
    table->capacity_power = HASHTABLE_INIT_POWER;
    table->count = 0;
}
