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
    #include <project_starter/hashtable.h>


typedef struct {
    char *name;
    char *value;
} ConfigValue;


void config_load_variables(const char *config_path, Hashtable *variables);


#endif
