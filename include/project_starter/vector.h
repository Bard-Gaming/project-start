/*
** BARDSHELL PROJECT, 2025
** Module: Vector
** File description:
** Header file for everything
** related to vectors
*/

#ifndef PROJECT_STARTER_VECTOR_H
    #define PROJECT_STARTER_VECTOR_H
    #include <project_starter/types.h>

    #define VECTOR_INIT_CAPACITY 10
    #define VECTOR_GROWTH_FACTOR 2


struct Vector {
    void **data;
    size_t count;
    size_t capacity;
};


void vector_push_back(Vector *vector, void *item);
void vector_remove_fast(Vector *vector, size_t index);

void vector_reserve(Vector *vector, size_t capacity);
void vector_grow(Vector *vector);

void vector_delete(Vector *vector, VectorItemFnc free_item);


#endif
