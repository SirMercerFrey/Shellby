#include "minishell.h"

t_shell	*create_shell(char **envp)
{
	t_shell		*new_shell;

	new_shell = (t_shell *)(malloc(sizeof(t_shell)));
	if (!new_shell)
		return (NULL);
	new_shell->cap = NULL;
	new_shell->envp = copy_envp(envp);
	if (!new_shell->envp)
	{
		free(new_shell);
		return (NULL);
	}
	new_shell->exit_status = 42;
	return (new_shell);
}

size_t	envp_len(char **envp)
{
	size_t	i;

	if (!envp || !*envp)
		return (0);
	i = 0;
	while (envp[i])
		++i;
	return (i);
}

char	**copy_envp(char **envp)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	**new_envp;

	len = envp_len(envp);
	new_envp = (char **)(malloc(sizeof(char *) * (len + 1)));
	if (!new_envp)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_envp[i] = ft_strdup(envp[i]);
		if (!new_envp[i])
		{
			j = 0;
			while (j < i)
				free(new_envp[j++]);
			free(new_envp);
			return (NULL);
		}
		++i;
	}
	new_envp[len] = NULL;
	return (new_envp);
}

void	free_shell(t_shell *shell)
{
	size_t	i;

	i = 0;
	while (shell->envp[i])
	{
		free(shell->envp[i]);
		++i;
	}
	free(shell->envp);
	free(shell);
}

void	handle_sigint(int signum)
{
	(void)signum;

	ft_printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
	
