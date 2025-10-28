
#include<minishell.h>

void builtin_pwd(t_cmd *cmd)
{
    char *full_path;

    if (cmd->argv[1])
        ft_putstr_fd("pwd: too many args\n", 2);
    else
    {
        full_path = getcwd(NULL, 0);
        if (full_path)
        {
            printf("%s\n", full_path);
            free(full_path);
        }
        else
            perror("getcwd");
    }
}

void builtin_export(t_cmd *cmd, char ***envp)
{
    size_t i = 1;

    if (!cmd->argv[1])
    {
        builtin_env(envp);
        return;
    }

    while (cmd->argv[i])
    {
        char *arg = cmd->argv[i];
        char *equal_sign = strchr(arg, '=');
        printf("TEST\n");
        if (equal_sign)
        {
            size_t key_len = equal_sign - arg;
            char *key = ft_strndup(arg, key_len);
            char *value = ft_strdup(equal_sign + 1);

            if (!key || !value)
            {
                fprintf(stderr, "export: allocation failed\n");
                free(key);
                free(value);
                return;
            }

            ft_setenv(key, value, envp);
            free(key);
            free(value);
        }
        else
        {
            if (!ft_getenv(arg, strlen(arg), *envp))
                ft_setenv(arg, "", envp);
        }
        i++;
    }
}

void    builtin_cd(t_cmd *cmd, char ***envp)
{
    char    *cwd;
    char    *oldpwd;
    char    *target;

    oldpwd = getcwd(NULL, 0);
    if (!oldpwd)
        perror("getcwd");

    if (cmd->argv[1])
    {
        target = cmd->argv[1];
    }
    else
        target = ft_getenv("HOME", 4, *envp);

    if (!target)
    {
        fprintf(stderr, "cd: HOME not set\n");
        free(oldpwd);
        return;
    }

    if (chdir(target) != 0)
    {
        perror("cd");
        free(oldpwd);
        return;
    }

    cwd = getcwd(NULL, 0);
    printf("OLD: %s\n", oldpwd);
    printf("CWD: %s\n", cwd);
    if (oldpwd)
        ft_setenv("OLDPWD", oldpwd, envp);

    printf("ICI ICI\n");
    if (cwd)
        ft_setenv("PWD", cwd, envp);

    free(oldpwd);
    free(cwd);
}

void builtin_unset(t_cmd *cmd, char ***envp)
{
    size_t i = 1;

    if (!cmd->argv[1])
        return;

    while (cmd->argv[i])
    {
        char *key = cmd->argv[i];
        size_t key_len = strlen(key);
        size_t j = 0;
        size_t count = 0;

        while ((*envp)[count])
            count++;

        char **new_env = malloc(sizeof(char *) * (count + 1));
        if (!new_env)
            return;

        size_t k = 0;
        j = 0;
        while ((*envp)[j])
        {
            if (!(strncmp((*envp)[j], key, key_len) == 0 && (*envp)[j][key_len] == '='))
            {
                new_env[k++] = (*envp)[j];
            }
            else
            {
                free((*envp)[j]);
            }
            j++;
        }

        new_env[k] = NULL;

        free(*envp);
        *envp = new_env;

        i++;
    }
}

void builtin_env(char ***envp)
{
    int i = 0;

    if (!(*envp))
        return;

    while ((*envp)[i])
    {
        printf("%s\n", (*envp)[i]);
        i++;
    }
}


