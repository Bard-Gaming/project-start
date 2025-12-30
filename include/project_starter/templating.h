/*
** EPITECH PROJECT, 2025
** Module: Templating
** File description:
** Header file for everything
** related to templating
*/

#ifndef PROJECT_STARTER_TEMPLATING_H
    #define PROJECT_STARTER_TEMPLATING_H
    #include <project_starter/hashtable.h>

    #define _GNU_SOURCE  // for GNU's basename()
    #include <stdbool.h>
    #include <stddef.h>
    #include <stdio.h>

    #define TMPL_MAX_FILE_SIZE 102400
    #define TMPL_FILE_EXTENSION "template"


typedef struct {
    const char *language;
    Hashtable variables;
} TemplateContext;


TemplateContext template_create_context(void);
char *template_parse_content(const Hashtable *variables, const char *src);

void template_generate(const TemplateContext *context);
bool template_generate_file(const Hashtable *vars, const char *src_path, const char *dest_dir);
bool template_generate_from_directory(const Hashtable *vars, const char *dir_path, const char *dest_dir);


#endif
