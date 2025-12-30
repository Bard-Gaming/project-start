/*
** EPITECH PROJECT, 2025
** Module: Templating
** File description:
** Implementation for
** Function Name
*/

#include <project_starter/templating.h>
#include <project_starter/string.h>


/**
 * Reads the template stream into
 * a string, replacing template variables
 * by their value, as defined by the
 * template context.
 *
 * If an error occurs, NULL is returned.
 *
 * The returned string needs to be freed
 * by the user.
 */
char *template_parse_stream(const TemplateContext *context, FILE *read_stream)
{
    char read_buffer[TMPL_READ_BUFFER_SIZE] = { 0 };
    String result = { 0 };
    size_t read_count;

    do {
        read_count = fread(read_buffer, sizeof(char), TMPL_READ_BUFFER_SIZE, read_stream);
        if (ferror(read_stream)) {
            string_delete(&result);
            return NULL;
        }
        string_addmem(&result, read_buffer, read_count);
    } while (read_count == TMPL_READ_BUFFER_SIZE);
    if (result.capacity == 0)
        string_addchr(&result, '\0');
    return result.c_str;
}
