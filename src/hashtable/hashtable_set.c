/*
** EPITECH PROJECT, 2025
** Module: Hashtable
** File description:
** Implementation for
** hashtable_set
*/

#include <project_starter/hashtable.h>
#include <project_starter/memory.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/**
 * Creates a new bucket in the hashtable
 * based on a given key.
 */
static HashtableBucket *create_new_bucket(Hashtable *table, const char *key)
{
    size_t index = hashtable_hash(table->capacity_power, key);
    HashtableBucket **head_bucket = table->buckets + index;
    HashtableBucket *new_bucket = xmalloc(sizeof(HashtableBucket));

    new_bucket->key = strdup(key);
    new_bucket->next = *head_bucket;
    *head_bucket = new_bucket;
    table->count++;
    return new_bucket;
}

/**
 * Grows the capacity of a given hashtable,
 * rehashing all stored values.
 */
static void grow_hashtable(Hashtable *table)
{
    size_t old_capacity = 1UL << table->capacity_power;
    HashtableBucket **new_buffer = xmalloc((old_capacity << 1) * sizeof(HashtableBucket *));

    table->capacity_power++;
    for (size_t i = 0; i < old_capacity; i++) {
        while (table->buckets[i] != NULL) {
            HashtableBucket *bucket = table->buckets[i];
            table->buckets[i] = bucket->next;

            size_t new_index = hashtable_hash(table->capacity_power, bucket->key);
            bucket->next = new_buffer[new_index];
            new_buffer[new_index] = bucket;
        }
    }
    free(table->buckets);
    table->buckets = new_buffer;
}

/**
 * Sets a value in the hashtable,
 * increasing the table's capacity
 * when required.
 * If the key is already associated
 * to a value, the value will be overwritten.
 */
void hashtable_set(Hashtable *table, const char *key, void *value)
{
    HashtableBucket *bucket = hashtable_get_bucket(table, key);

    if (bucket == NULL) {
        float capacity = 1UL << table->capacity_power;

        if ((float)table->count >= capacity * HASHTABLE_LOAD_FACTOR)
            grow_hashtable(table);

        bucket = create_new_bucket(table, key);
    }

    bucket->data = value;
}
