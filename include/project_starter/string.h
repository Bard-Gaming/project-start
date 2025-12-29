/*
** EPITECH PROJECT, 2025
** Module: String
** File description:
**
*/

#ifndef PROJECT_STARTER_STRING_H
    #define PROJECT_STARTER_STRING_H
    #include <stddef.h>

    #define STRING_START_CAPACITY 12
    #define STRING_GROWTH 2


typedef struct {
    char *c_str;
    size_t length;
    size_t capacity;
} String;


String string_new(char *str);
String string_from_reference(const char *ref);
void string_addchr(String *str, char c);
void string_addstr(String *str, const char *restrict ref);
void string_reserve(String *str, size_t capacity);
void string_delete(String *str);


#endif
