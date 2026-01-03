/*
** EPITECH PROJECT, 2025
** Module: Vector
** File description:
** Implementation for
** vector_push_back
*/

#include <project_starter/vector.h>


/**
 * Appends the given item
 * to the end of the vector,
 * growing the vector's capacity
 * as needed.
 */
void vector_push_back(Vector *vector, void *item)
{
    if (vector->count + 1 > vector->capacity)
        vector_grow(vector);

    vector->data[vector->count] = item;
    vector->count++;
}
