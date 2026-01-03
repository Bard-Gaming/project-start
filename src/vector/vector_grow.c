/*
** EPITECH PROJECT, 2025
** Module: Vector
** File description:
** Implementation for
** vector_grow
*/

#include <project_starter/vector.h>


/**
 * Centralized function to grow a
 * vector's capacity based on the
 * defined init capacity and growth
 * factor.
 *
 * A user should avoid using this
 * function.
 */
void vector_grow(Vector *vector)
{
    size_t new_capacity = vector->capacity > 0
        ? vector->capacity * VECTOR_GROWTH_FACTOR
        : VECTOR_INIT_CAPACITY;

    vector_reserve(vector, new_capacity);
}
