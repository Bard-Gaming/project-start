/*
** EPITECH PROJECT, 2025
** Module: Hashtable
** File description:
** Implementation for
** hashtable_delete
*/

#include <project_starter/hashtable.h>
#include <stdlib.h>


/**
 * The default HashtableDataDeleteFnc
 * that should be used when NULL is
 * provided.
 */
static void default_data_delete_fnc(const char *key, void *data)
{
    return;  // intentionally don't do anything
}

/**
 * Deletes all contents of a given table,
 * freeing up all the memory it uses.
 *
 * The given HashtableDataDeleteFnc can
 * be set to NULL, in which case the stored
 * data won't get freed.
 *
 * The table subsequently needs to be
 * initialized using hashtable_init().
 */
void hashtable_delete(Hashtable *table, HashtableDataDeleteFnc free_data)
{
    size_t capacity = 1UL << table->capacity_power;

    free_data = free_data ?: default_data_delete_fnc;

    for (size_t i = 0; i < capacity; i++) {
        while (table->buckets[i] != NULL) {
            HashtableBucket *bucket = table->buckets[i];
            table->buckets[i] = bucket->next;

            free_data(bucket->key, bucket->data);
            free(bucket->key);
            free(bucket);
        }
    }
    free(table->buckets);
}
