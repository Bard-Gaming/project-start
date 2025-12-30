/*
** EPITECH PROJECT, 2025
** Module: Hashtable
** File description:
** Implementation for
** hashtable_get_bucket
*/

#include <project_starter/hashtable.h>
#include <string.h>


/**
 * Retrieves the bucket associated to
 * the given key. If no bucket is found,
 * NULL is returned instead.
 */
HashtableBucket *hashtable_get_bucket(const Hashtable *table, const char *key)
{
    size_t index = hashtable_hash(table->capacity_power, key);
    HashtableBucket *bucket = table->buckets[index];

    while (bucket != NULL && strcmp(bucket->key, key) != 0) {
        bucket = bucket->next;
    }
    return bucket;
}
