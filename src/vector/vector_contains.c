/*
** EPITECH PROJECT, 2025
** Module: Vector
** File description:
** Implementation for
** vector_contains
*/

#include <project_starter/vector.h>
#include <string.h>


/**
 * Determines whether the given
 * item is contained in the vector
 * or not.
 *
 * This uses the given CompareFnc, which
 * must return 0 if both items given to
 * it are equal.
 *
 * If the given CompareFnc is NULL, strcmp()
 * is used.
 */
bool vector_contains(Vector *vector, const void *item, CompareFnc cmp)
{
    cmp = cmp ?: (CompareFnc)strcmp;

    for (size_t i = 0; i < vector->count; i++) {
        if (cmp(item, vector->data[i]) == 0)
            return true;
    }

    return false;
}
