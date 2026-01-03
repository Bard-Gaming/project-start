/*
** EPITECH PROJECT, 2025
** Module: Templating
** File description:
** Implementation for
** template_generate
*/

#include <project_starter/templating.h>
#include <project_starter/string.h>
#include <project_starter/common.h>
#include <project_starter/os.h>
#include <stdio.h>
#include <sys/stat.h>


/**
 * Generates all file templates for
 * the project.
 *
 * Returns true on success and false
 * on failure.
 */
bool template_generate(const TemplateContext *context)
{
    String common_tmpl_path = string_from_reference(PROJECT_STARTER_CONFIG_PATH);;
    String lang_tmpl_path = string_copy(&common_tmpl_path);
    bool success;

    string_join_path(&common_tmpl_path, "templates/common/");

    string_join_path(&lang_tmpl_path, "templates/");
    string_join_path(&lang_tmpl_path, context->language);

    const char *project_dir = context->names[0] ?: ".";
    if (!os_is_empty_directory(project_dir)) {
        fprintf(stderr, "critical error: directory %s is not empty\n", project_dir);
        string_delete(&common_tmpl_path);
        string_delete(&lang_tmpl_path);
        return false;
    }

    mkdir(project_dir, 0755);

    success = template_generate_from_directory(context, common_tmpl_path.c_str, project_dir);
    if (!success) {
        fputs("error: failed to generate common templates\n", stderr);
    }

    success = template_generate_from_directory(context, lang_tmpl_path.c_str, project_dir);
    if (!success) {
        fprintf(stderr, "error: failed to generate %s templates\n", context->language);
    }

    if (context->should_initialize_git)
        template_generate_git(context, project_dir);

    string_delete(&common_tmpl_path);
    string_delete(&lang_tmpl_path);

    return true;
}
