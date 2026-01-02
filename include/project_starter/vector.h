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


struct Vector {
    void *data;
    size_t count;
    size_t capacity;
};


void vector_push_back(Vector *vector, void *data);


#endif
