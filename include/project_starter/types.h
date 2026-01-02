/*
** BARDSHELL PROJECT, 2025
** Module: Types
** File description:
** Header file for all
** type definitions used
** in the project
*/

#ifndef PROJECT_STARTER_TYPES_H
    #define PROJECT_STARTER_TYPES_H
    #include <stdbool.h>
    #include <stddef.h>


/////////////////////////////////////////////////
//                                             //
//                  Structures                 //
//                                             //
/////////////////////////////////////////////////

typedef struct TemplateContext TemplateContext;
typedef struct HashtableBucket HashtableBucket;
typedef struct ConfigValue ConfigValue;
typedef struct Hashtable Hashtable;
typedef struct String String;


/////////////////////////////////////////////////
//                                             //
//                  Functions                  //
//                                             //
/////////////////////////////////////////////////

typedef void (*HashtableDataDeleteFnc)(const char *key, void *data);
typedef bool (*CharPredicate)(char);


#endif
