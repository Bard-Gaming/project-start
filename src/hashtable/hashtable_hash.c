/*
** EPITECH PROJECT, 2025
** Module: Hashtable
** File description:
** Implementation for
** hashtable_hash
*/

#include <project_starter/hashtable.h>


/**
 * Hashes the given key into an unsigned
 * integer less than the available space
 * (as specified by capacity_power).
 */
size_t hashtable_hash(unsigned char capacity_power, const char *key)
{
    size_t capacity_limiter = (1UL << capacity_power) - 1;
    size_t result = 0;

    for (size_t i = 0; key[i] != '\0'; i++) {
        result = (result + key[i] + i) * HASHING_FACTOR;
    }

    return result & capacity_limiter;  // equivalent to % (capacity_limiter + 1)
}
