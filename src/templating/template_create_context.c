/*
** EPITECH PROJECT, 2025
** Module: Templating
** File description:
** Implementation for
** template_create_context
*/

#include "project_starter/config.h"
#include <project_starter/templating.h>
#include <project_starter/hashtable.h>
#include <project_starter/string.h>
#include <project_starter/common.h>
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
    // Need to be freed
    hashtable_set(&context->variables, "year", get_current_year());
    hashtable_set(&context->variables, "time", strdup(os_readable_time()));
    hashtable_set(&context->variables, "author", get_username());
}

/**
 * Loads the variables defined in
 * the user's config.
 */
static void load_variables_from_config(TemplateContext* context)
{
    String cfg_path = string_from_reference(PROJECT_STARTER_CONFIG_PATH);
    string_join_path(&cfg_path, PROJECT_STARTER_VARS_CFG_NAME);

    config_load_variables(cfg_path.c_str, &context->variables);

    string_delete(&cfg_path);
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
    load_variables_from_config(&context);
    return context;
}
