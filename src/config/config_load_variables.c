/*
** EPITECH PROJECT, 2025
** Module: Config
** File description:
** Implementation for
** config_load_variables
*/

#include <project_starter/config.h>
#include <stdlib.h>


/**
 * Loads template variables from
 * the specified file into the
 * given hashtable.
 */
void config_load_variables(const char *file_path, Hashtable *variables)
{
    FILE *cfg_file = fopen(file_path, "rt");

    ConfigValue *value = config_parse_value(cfg_file);
    while (value != NULL) {
        hashtable_set(variables, value->name, value->value);

        free(value->name);
        free(value->value);
        value = config_parse_value(cfg_file);
    }

    fclose(cfg_file);
}
