/*
** EPITECH PROJECT, 2025
** Module: Templating
** File description:
** Implementation for
** template_generate_file
*/

#include <project_starter/templating.h>
#include <project_starter/string.h>
#include <stdlib.h>
#include <string.h>


/**
 * Retrieves the output's file path based
 * on the source path and the destination.
 *
 * The resulting string needs to be freed
 * by the user.
 *
 * Returns NULL on error.
 *
 * Examples:
 * src_path                              |  dest_dir  |  result
 * templates/C/Makefile.template         | .          | ./Makefile
 * templates/common/.gitignore.template  | project    | project/.gitignore
 */
static char *output_file_path(const char *src_path, const char *dest_dir)
{
    String result = { 0 };
    char *filename = strdup(basename(src_path));
    char *extension = strrchr(filename, '.');
    size_t dest_dir_len = strlen(dest_dir);

    if (extension == NULL || strcmp(extension + 1, TMPL_FILE_EXTENSION) != 0) {
        free(filename);
        return NULL;
    }
    *extension = '\0';
    if (dest_dir[dest_dir_len - 1] == '/')
        dest_dir_len--;
    string_addmem(&result, dest_dir, dest_dir_len);
    string_addchr(&result, '/');
    string_addstr(&result, filename);
    free(filename);
    return result.c_str;
}

/**
 * Opens the output file needed
 * for the given source path and
 * destination directory.
 *
 * Returns NULL on error.
 */
static FILE *open_output_file(const char *src_path, const char *dest_dir)
{
    char *file_path = output_file_path(src_path, dest_dir);
    FILE *output_file;

    if (file_path == NULL)
        return NULL;
    output_file = fopen(file_path, "wb");
    free(file_path);
    return output_file;
}

/**
 * Generates a file from a template in the
 * target directory using the given template
 * context to fill in values.
 *
 * Returns true on success and false on error.
 */
bool template_generate_file(const TemplateContext *context, const char *src_path, const char *dest_dir)
{
    FILE *src_file = fopen(src_path, "rb");
    FILE *out_file;
    char *content;

    if (src_file == NULL)
        return false;
    content = template_parse_stream(context, src_file);
    fclose(src_file);
    out_file = open_output_file(src_path, dest_dir);
    if (out_file == NULL) {
        free(content);
        return false;
    }
    fputs(content, out_file);
    free(content);
    return true;
}
