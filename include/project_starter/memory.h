/*
** BARDSHELL PROJECT, 2025
** Module: Memory
** File description:
** Header file for memory
** utils
*/

#ifndef PROJECT_STARTER_MEMORY_H
    #define PROJECT_STARTER_MEMORY_H
    #include <stdlib.h>

    #define PS_UNLIKELY(x) __builtin_expect((x), 0)
    #define PS_MEM_ERROR 127


void *xmalloc(size_t size);
void *xcalloc(size_t nmemb, size_t size);
void *xrealloc(void *ptr, size_t size);


#endif
