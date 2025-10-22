
#include<minishell.h>

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
