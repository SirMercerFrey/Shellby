#include "minishell.h"

int	isbuiltin(t_shell *shell)
{
	t_cmd	*tmp;

	tmp = shell->cap->next;
    if (ft_strcmp(tmp->argv[0], "pwd") == 0)
        return (1);
    if (ft_strcmp(tmp->argv[0], "cd") == 0)
        return (1);
    if (ft_strcmp(tmp->argv[0], "export") == 0)
        return (1);
    if (ft_strcmp(tmp->argv[0], "unset") == 0)
        return (1);
    if (ft_strcmp(tmp->argv[0], "env") == 0)
        return (1);
    return (0);
}

void    exec_builtins(t_shell *shell)
{
	t_cmd	*tmp;

    if (ft_strncmp(tmp->argv[0], "pwd", 3) == 0)
		builtin_pwd(tmp);
	else if (ft_strncmp(tmp->argv[0], "cd", 2) == 0)
		builtin_cd(tmp, &shell->envp);
	else if ((ft_strncmp(tmp->argv[0], "export", 6) == 0))
		builtin_export(tmp, &shell->envp);
	else if ((ft_strncmp(tmp->argv[0], "unset", 5) == 0))
		builtin_unset(tmp, &shell->envp);
	else if ((ft_strncmp(tmp->argv[0], "env", 3) == 0))
		builtin_env(&shell->envp);
}

void	exec_cmd(t_shell *shell)
{
	pid_t	pid;
	int		status;
	t_cmd	*tmp;

	tmp = shell->cap->next;
	tmp->cmd_path = find_path(tmp->argv[0], shell->envp);
	pid = fork();
	if (pid == 0)
	{
		if (!tmp->cmd_path)
			ft_printf("Command not found: %s\n", tmp->argv[0]);
		else
		{
			execve(tmp->cmd_path, tmp->argv, shell->envp);
			perror("execve");
		}
		ft_free_split(tmp->argv); //gne ?
		free(tmp->cmd_path);
	}
	else if (pid > 0)
		waitpid(pid, &status, 0);
	else
		perror("fork");
}

void ft_free_split(char **split)
{
    if (!split) 
        return;

    for (int i = 0; split[i] != NULL; i++)
    {
        free(split[i]); 
    }

    free(split); 
}
