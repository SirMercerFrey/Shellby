/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 22:35:20 by mjustine          #+#    #+#             */
/*   Updated: 2025/09/23 22:35:22 by mjustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(int argc, char **argv, char **envp)
{
	char	**args;
	char	*path;
	char	*line;
	char *pwd;

	(void)argc;
	(void)argv;
	pwd = absolut_path();
	line = readline(pwd);
	prompt_loop(line, pwd, envp);
	free(pwd);
	return (0);
}

void	prompt_loop(char *line, char *pwd, char **envp)
{
	while (line != NULL)
	{
		if (*line)
		{
			add_history(line);
			if (isbuiltin(line))
				exec_builtins(line);
			else
				exec_cmd(line, envp);
		}
		free(line);
		pwd = absolut_path();
		line = readline(pwd);
	}
}

int isbuiltin(char *line)
{
	if (ft_strncmp(line, "pwd", 3) == 0)
		return(1);
	else if (ft_strncmp(line, "cd", 2) == 0)
		return(1);
	return(0);
}

void    exec_builtins(char *line)
{
    if (ft_strncmp(line, "pwd", 3) == 0)
		builtin_pwd();
	else if (ft_strncmp(line, "cd", 2) == 0)
		builtin_cd(line);
}

void	exec_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*path;
	pid_t	pid;
	int		status;

	pid = fork();
	
	if (pid == 0)
	{
		args = ft_split_char(cmd, ' ');
		path = find_path(args[0], envp);
		if (!path)
			printf("Command not found: %s\n", args[0]);
		else
		{
			execve(path, args, envp);
			perror("execve");
		}
		ft_free_split(args);
		free(path);
	}
	else if (pid > 0)
		waitpid(pid, &status, 0);
	else
		perror("fork");
}
