/*
** EPITECH PROJECT, 2025
** Module: Templating
** File description:
** Implementation for
** template_create_context
*/

#include <project_starter/templating.h>
#include <project_starter/hashtable.h>
#include <project_starter/os.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>


/**
 * Note: the returned string needs
 * to be free()d by the user.
 */
static char *get_current_year(void)
{
    time_t current_time = time(NULL);
    struct tm *time_info = localtime(&current_time);
    static char year_buffer[5] = { 0 };

    snprintf(year_buffer, 5, "%d", time_info->tm_year + 1900);
    return strdup(year_buffer);  // duplicate to avoid override
}

/**
 * Note: the returned string needs
 * to be free()d by the user.
 */
static char *get_username(void)
{
    struct passwd *user_info = getpwuid(getuid());
    if (user_info == NULL)
        return strdup("unknown");

    // duplicate to avoid override
    return strdup(user_info->pw_name);
}

/**
 * Loads default values into the
 * context's variables.
 */
static void load_defaults(TemplateContext *context)
{
    // May not be freed
    hashtable_set(&context->variables, "organisation", "EPITECH");

    // Need to be freed
    hashtable_set(&context->variables, "year", get_current_year());
    hashtable_set(&context->variables, "time", strdup(os_readable_time()));
    hashtable_set(&context->variables, "author", get_username());
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
        .should_initialize_git = false,
        .git_remote = NULL,
    };

    hashtable_init(&context.variables);
    load_defaults(&context);
    return context;
}
