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
    const char *names[2];
    Hashtable variables;

    bool should_initialize_git;
    const char *git_remote;
} TemplateContext;


// Context-related
TemplateContext template_create_context(void);
void template_delete_context(TemplateContext *context);
void template_register_context_names(TemplateContext *context);

// Utils
char *template_get_variable(const TemplateContext *context, const char *key);
char *template_parse_content(const TemplateContext *context, const char *src);
char **template_get_available_langs(const char *dir_path);

// Generation
void template_generate(const TemplateContext *context);
void template_generate_git(const TemplateContext *context, const char *path);
bool template_generate_file(const TemplateContext *context, const char *src_path, const char *dest_dir);
bool template_generate_from_directory(const TemplateContext *context, const char *dir_path, const char *dest_dir);


#endif
