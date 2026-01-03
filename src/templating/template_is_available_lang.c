/*
** EPITECH PROJECT, 2025
** Module: Templating
** File description:
** Implementation for
** template_is_available_lang
*/

#include <project_starter/templating.h>
#include <project_starter/string.h>
#include <project_starter/vector.h>
#include <project_starter/common.h>


/**
 * Determines if the language specified
 * by cmp_ref is an available language
 * or not.
 */
bool template_is_available_lang(const char *cmp_ref)
{
    String template_dir_path = string_from_reference(PROJECT_STARTER_CONFIG_PATH);
    string_join_path(&template_dir_path, "templates");

    Vector available_langs = template_get_available_langs(template_dir_path.c_str);
    string_delete(&template_dir_path);

    bool is_available = vector_contains(&available_langs, cmp_ref, NULL);

    vector_delete(&available_langs, vector_free_item);
    return is_available;
}
