/*
** EPITECH PROJECT, 2025
** Module: Templating
** File description:
** Header file for everything
** related to templating
*/

#ifndef PROJECT_STARTER_TEMPLATING_H
    #define PROJECT_STARTER_TEMPLATING_H
    #include <stddef.h>
    #include <stdio.h>

    #define TMPL_READ_BUFFER_SIZE 100


typedef struct {
    const char *name;
    const char *display_name;
    const char *project_org;
    const char *year;
} TemplateContext;


char *template_parse_stream(const TemplateContext *context, FILE *read_stream);


#endif
