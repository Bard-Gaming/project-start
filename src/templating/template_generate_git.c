/*
** EPITECH PROJECT, 2025
** Module: Templating
** File description:
** Implementation for
** template_generate_git
*/

#include <project_starter/templating.h>
#include <project_starter/string.h>
#include <project_starter/os.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>


/**
 * Runs the commands
 * git add .
 * git commit -m 'feat: initial commit'
 *
 * At the specified path.
 */
static void make_initial_commit(const char *path)
{
    const char *add_command[] = { "git", "-C", path, "add", ".",  NULL };
    const char *commit_command[] = { "git", "-C", path, "commit", "-m", "feat: initial commit",  NULL };

    os_exec_command(add_command);
    os_exec_command(commit_command);
}

/**
 * Initializes an empty git
 * repository at the given
 * path.
 */
static void initialize_git_repository(const char *path)
{
    const char *command[] = { "git", "-C", path, "init", NULL };

    os_exec_command(command);
}

/**
 * Determines if a file is allowed
 * based on its name.
 * Allowed files are the files:
 * - "."
 * - ".."
 * - ".git"
 */
static bool is_allowed_file(const char *name)
{
    if (name[0] != '.')
        return false;

    return
        (name[1] == '\0') ||             // "."
        (strcmp(name + 1, ".") == 0) ||  // ".."
        (strcmp(name + 1, "git") == 0);  // ".git"
}

/**
 * Determines if the given directory
 * contains files / directories other
 * than '.git/'
 */
static bool dir_contains_extra_files(const char *dir_path)
{
    DIR *dirp = opendir(dir_path);
    if (dirp == NULL)
        return false;

    struct dirent *entry = readdir(dirp);
    while (entry != NULL) {
        if (!is_allowed_file(entry->d_name)) {
            closedir(dirp);
            return true;
        }

        entry = readdir(dirp);
    }

    closedir(dirp);
    return false;
}

/**
 * Clones a git repository
 * from a given remote.
 */
static void clone_empty_git_repository(const char *path, const char **remote)
{
    char temp_dir[] = "/tmp/project_start_XXXXXX/.git";
    char *dir_end = strrchr(temp_dir, '/');
    *dir_end = '\0';

    char *result = mkdtemp(temp_dir);
    if (result == NULL) {
        fputs("critical error: failed to create temporary directory\n", stderr);
        exit(1);
    }

    const char *clone_command[] = { "git", "-C", temp_dir, "clone", *remote, ".", NULL };
    os_exec_command(clone_command);

    if (dir_contains_extra_files(temp_dir)) {
        fputs(
            "error: specified remote already contains files\n"
            "defaulting to empty git repository\n", stderr
        );
        *remote = NULL;
        return;
    }

    *dir_end = '/';
    os_move(temp_dir, path);  // move .git dir into project dir
}

/**
 * Generates the necessary git
 * repository based on the template
 * context.
 */
void template_generate_git(const TemplateContext *context, const char *path)
{
    if (!context->should_initialize_git)
        return;

    const char *git_remote = context->git_remote;
    if (git_remote != NULL) {
        clone_empty_git_repository(path, &git_remote);
    }

    // git_remote might have changed since last check,
    // so check again instead of using else stmt
    if (git_remote == NULL) {
        initialize_git_repository(path);
    }

    make_initial_commit(path);
}
