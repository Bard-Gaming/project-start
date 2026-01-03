/*
** EPITECH PROJECT, 2025
** Module: Vector
** File description:
** Implementation for
** vector_delete
*/

#include <project_starter/vector.h>
#include <stdlib.h>
#include <string.h>


/**
 * Deletes the vector and all
 * data associated to it.
 *
 * If the given free_item function
 * is not NULL, it is called for
 * every item in the vector. This
 * allows freeing up the memory of
 * the items stored in the vector,
 * if required.
 */
void vector_delete(Vector *vector, VectorItemFnc free_item)
{
    if (free_item != NULL) {
        for (size_t i = 0; i < vector->count; i++) {
            free_item(i, vector->data[i]);
        }
    }

    free(vector->data);
    memset(vector, 0, sizeof(Vector));
}
