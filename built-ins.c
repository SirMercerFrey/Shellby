
#include<minishell.h>

char *absolut_path(void)
{
    char *full_path = getcwd(NULL, 0);
    char *last_slash = ft_strrchr(full_path, '/');
    char *folder_name;
    char *result;

    if (last_slash && *(last_slash + 1))
        folder_name = last_slash + 1;
    else
        folder_name = full_path;

    result = ft_strjoin(folder_name, " > ");
    free(full_path);
    return result;
}

void builtin_pwd(void)
{
    char *full_path;

    full_path = getcwd(NULL, 0);
    printf("%s\n", full_path);
}

void builtin_cd(char *new_dir)
{
    char **split;

    split = ft_split(new_dir);
    chdir(split[1]);
}
