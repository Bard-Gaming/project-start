/*
** EPITECH PROJECT, 2025
** Module: Templating
** File description:
** Implementation for
** template_generate
*/

#include <project_starter/templating.h>
#include <project_starter/string.h>
#include <stdio.h>
#include <sys/stat.h>


/**
 * Generates all file templates for
 * the project.
 */
void template_generate(const TemplateContext *context)
{
    String config_path = string_from_reference(PROJECT_STARTER_CONFIG_PATH);
    String common_tmpl_path = string_copy(&config_path);
    String lang_tmpl_path = string_copy(&config_path);
    bool success;

    string_addstr(&common_tmpl_path, "templates/common/");

    string_addstr(&lang_tmpl_path, "templates/");
    string_addstr(&lang_tmpl_path, context->language);

    const char *project_dir = context->names[0] ?: ".";
    mkdir(project_dir, 0755);

    success = template_generate_from_directory(&context->variables, common_tmpl_path.c_str, project_dir);
    if (!success) {
        fputs("error: failed to generate common templates\n", stderr);
    }

    success = template_generate_from_directory(&context->variables, lang_tmpl_path.c_str, project_dir);
    if (!success) {
        fprintf(stderr, "error: failed to generate %s templates\n", context->language);
    }
}
