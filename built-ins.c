
#include<minishell.h>

void builtin_pwd(t_cmd *cmd)
{
    char *full_path;

    if (cmd->argv[1])
        ft_putstr_fd("pwd: too many args", 2);
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

void builtin_cd(t_cmd *cmd)
{
    if (cmd->argv[1])
        chdir(cmd->argv[1]);
    else
        chdir("/home");
}
