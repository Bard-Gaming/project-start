/*
** EPITECH PROJECT, 2025
** Module: Templating
** File description:
** Implementation for
** template_delete_context
*/

#include <project_starter/templating.h>
#include <project_starter/hashtable.h>
#include <stdlib.h>
#include <string.h>


static const char *keys_to_free[] = {
    "year", "time", "author",
    NULL
};

static bool should_free_data(const char *key)
{
    for (size_t i = 0; keys_to_free[i] != NULL; i++) {
        if (strcmp(key, keys_to_free[i]) != 0)
            continue;
        return true;
    }
    return false;
}

/**
 * Frees up the entry associated
 * to the given key, as necessary.
 */
static void free_hashtable_entry(const char *key, void *data)
{
    if (!should_free_data(key))
        return;

    free(data);
}

/**
 * Frees the data allocated for the
 * context and resets its values
 * back to 0.
 */
void template_delete_context(TemplateContext *context)
{
    hashtable_delete(&context->variables, free_hashtable_entry);

    memset(context, 0, sizeof(TemplateContext));
}
