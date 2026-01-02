/*
** EPITECH PROJECT, 2025
** Module: Config
** File description:
** Implementation for
** config_parse_value
*/

#include <project_starter/config.h>
#include <project_starter/string.h>
#include <stdbool.h>



/**
 * Skips all chars in the given stream
 * until c is read or reading from the
 * stream fails.
 *
 * Returns true on success and false on
 * failure.
 */
static bool advance_past(FILE *stream, char c)
{
    char current;
    bool success;

    success = fread(&current, sizeof(char), 1, stream);
    while (success && current != c) {
        success = fread(&current, sizeof(char), 1, stream);
    }

    return success;
}

/**
 * Predicate function that determines
 * if a character is part of a config
 * entry's name or not.
 */
static bool is_identifier_char(char c)
{
    return
        ('a' <= c && c <= 'z') ||
        ('A' <= c && c <= 'Z') ||
        ('0' <= c && c <= '9') ||
        (c == '_') ||
        (c == '-') ||
        (c == '.');
}

/**
 * Predicate function that determines
 * if a character is part of a config
 * entry's value or not.
 */
static bool is_value_char(char c)
{
    return
        (c != '\0') &&
        (c != '\n') &&
        (c != '"');
}

/**
 * Reads chars into the given
 * string buffer until the stream
 * can't be read anymore or the
 * given predicate returns false.
 */
static bool read_content(String *buffer, FILE *stream, CharPredicate condition)
{
    bool read_success;
    char current;

    read_success = fread(&current, sizeof(char), 1, stream);
    while (read_success && condition(current)) {
        string_addchr(buffer, current);

        read_success = fread(&current, sizeof(char), 1, stream);
    }

    if (!read_success)
        return false;

    // put offending char back
    return ungetc(current, stream) == current;
}

/**
 * Small cleanup utility
 */
static ConfigValue *config_parse_error(String *name, String *value)
{
    string_delete(name);
    string_delete(value);
    return NULL;
}

/**
 * Parses a config value,
 * returning a pointer to it
 * on success.
 *
 * On failure, returns NULL
 * and sets should_continue
 * to false.
 */
static ConfigValue *parse_config_value(char start, FILE *stream, bool *should_continue)
{
    static ConfigValue value = { 0 };
    String config_name = { 0 };
    String config_value = { 0 };

    // name
    string_addchr(&config_name, start);
    *should_continue = read_content(&config_name, stream, is_identifier_char);
    if (!*should_continue)
        return config_parse_error(&config_name, &config_value);

    // =
    *should_continue = advance_past(stream, '=');
    if (!*should_continue)
        return config_parse_error(&config_name, &config_value);

    // "value"
    *should_continue = advance_past(stream, '"');
    if (!*should_continue)
        return config_parse_error(&config_name, &config_value);

    *should_continue = read_content(&config_value, stream, is_value_char);
    if (!*should_continue)
        return config_parse_error(&config_name, &config_value);

    if (fgetc(stream) != '"') {
        fputs("unterminated string\n", stderr);
        *should_continue = false;
        return config_parse_error(&config_name, &config_value);
    }

    // result
    value.name = config_name.c_str;
    value.value = config_value.c_str;
    return &value;
}

/**
 * Handles a single read character
 * from the given stream.
 */
static ConfigValue *handle_char(char c, FILE *stream, bool *should_continue)
{
    ConfigValue *result;

    switch (c) {
        case '#':
            *should_continue = advance_past(stream, '\n');
            return NULL;
        case ' ':
        case '\t':
        case '\n':
            *should_continue = true;  // redundant
            return NULL;
        default:
            result = parse_config_value(c, stream, should_continue);
            if (result != NULL)
                *should_continue = false;

            return result;
    }
}


/**
 * Advances the file stream
 * until a config value is
 * encountered or the stream
 * ends.
 *
 * On success, a pointer to a
 * valid ConfigValue is returned.
 * On failure, NULL is returned.
 *
 * Note: the returned pointer must
 * not be passed to free(), as it's
 * stored under static memory.
 * Furthermore, subsequent calls to
 * the function might change its
 * contents.
 */
ConfigValue *config_parse_value(FILE *stream)
{
    ConfigValue *result;
    bool continue_reading;
    char current;

    continue_reading = fread(&current, sizeof(char), 1,  stream);
    while (continue_reading) {
        result = handle_char(current, stream, &continue_reading);
        if (!continue_reading)
            break;

        continue_reading = fread(&current, sizeof(char), 1,  stream);
    }

    return result;
}
