/*
** BARDSHELL PROJECT, 2025
** Module: Config
** File description:
** Header file for everything
** related to the project-start
** config
*/

#ifndef PROJECT_STARTER_CONFIG_H
    #define PROJECT_STARTER_CONFIG_H
    #include <project_starter/types.h>
    #include <stdio.h>


struct ConfigValue {
    char *name;
    char *value;
};


void config_load_variables(const char *file_path, Hashtable *variables);
ConfigValue *config_parse_value(FILE *stream);


#endif
