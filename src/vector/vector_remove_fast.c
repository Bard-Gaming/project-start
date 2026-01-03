/*
** EPITECH PROJECT, 2025
** Module: Vector
** File description:
** Implementation for
** vector_remove_fast
*/

#include <project_starter/vector.h>


/**
 * Removes the element at the given
 * index in O(1) time. This is achieved
 * by swapping the element at the
 * last index with the element to be
 * removed, then decreasing the item
 * count (also called "swap and pop").
 *
 * This function does nothing if the
 * index is outside of the vector's
 * range.
 *
 * Important:
 * This operation does not preserve
 * the order of the items in the
 * vector.
 */
void vector_remove_fast(Vector *vector, size_t index)
{
    if (index >= vector->count)
        return;

    vector->data[index] = vector->data[vector->count - 1];
    vector->count--;
}
