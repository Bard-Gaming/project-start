/*
** EPITECH PROJECT, 2025
** Module: Hashtable
** File description:
** Implementation for
** hashtable_init
*/

#include <project_starter/hashtable.h>
#include <project_starter/memory.h>
#include <stdlib.h>
#include <stdio.h>


/**
 * Initializes a hashtable.
 * This is required to use operations
 * on the hashtable.
 */
void hashtable_init(Hashtable *table)
{
    table->buckets = xcalloc(
        1UL << HASHTABLE_INIT_POWER,
        sizeof(HashtableBucket *)
    );

    table->capacity_power = HASHTABLE_INIT_POWER;
    table->count = 0;
}
