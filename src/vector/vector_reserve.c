/*
** EPITECH PROJECT, 2025
** Module: Vector
** File description:
** Implementation for
** vector_reserve
*/

#include <project_starter/vector.h>
#include <project_starter/memory.h>


/**
 * Increases the capacity of the vector
 * to at least the given capacity. If the
 * vector's capacity is already equal to
 * or greater than the given capacity,
 * this does nothing.
 */
void vector_reserve(Vector *vector, size_t capacity)
{
    if (vector->capacity >= capacity)
        return;

    vector->data = xreallocarray(vector->data, capacity, sizeof(void *));
    vector->capacity = capacity;
}
