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
String string_copy(const String *str);

void string_addchr(String *str, char c);
void string_addstr(String *str, const char *restrict ref);
void string_addmem(String *str, const char *restrict mem, size_t size);
void string_join_path(String *path_start, const char *path_end);

void string_reserve(String *str, size_t capacity);

void string_upper(String *str);
void string_lower(String *str);

void string_delete(String *str);
void string_clear(String *str);


#endif
