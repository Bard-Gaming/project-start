/*
** EPITECH PROJECT, 2025
** Module: Hashtable
** File description:
** Implementation for
** hashtable_get
*/

#include <project_starter/hashtable.h>


/**
 * Retrieves a value from the hashtable.
 * If the given key isn't associated to
 * any value, NULL is returned instead.
 */
void *hashtable_get(const Hashtable *table, const char *key)
{
    HashtableBucket *bucket = hashtable_get_bucket(table, key);

    return bucket != NULL
        ? bucket->data
        : NULL;
}
