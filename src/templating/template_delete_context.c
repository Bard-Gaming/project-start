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


/**
 * Frees up the entry associated
 * to the given key, as necessary.
 */
static void free_hashtable_entry(const char *key, void *data)
{
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
