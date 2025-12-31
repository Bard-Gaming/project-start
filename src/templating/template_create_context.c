/*
** EPITECH PROJECT, 2025
** Module: Templating
** File description:
** Implementation for
** template_create_context
*/

#include <project_starter/templating.h>
#include <project_starter/hashtable.h>
#include <time.h>


static char *get_current_year(void)
{
    time_t current_time = time(NULL);
    struct tm *time_info = localtime(&current_time);
    static char year_buffer[5] = { 0 };

    snprintf(year_buffer, 5, "%d", time_info->tm_year + 1900);
    return year_buffer;
}

/**
 * Loads default values into the
 * context's variables.
 */
static void load_defaults(TemplateContext *context)
{
    // get_current_year() returns a static ptr, but this shouldn't
    // be an issue since it always contains the same result, unless
    // the program is running whilst the year changes (which isn't
    // that much of an issue).
    hashtable_set(&context->variables, "year", get_current_year());
    hashtable_set(&context->variables, "project_org", "EPITECH");
}

/**
 * Creates a template context with
 * default values.
 */
TemplateContext template_create_context(void)
{
    TemplateContext context = {
        .names = { 0 },
        .language = "C",
        .variables = { 0 },
    };

    hashtable_init(&context.variables);
    load_defaults(&context);
    return context;
}
