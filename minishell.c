#include "minishell.h"

/*void	write_prompt(void)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		write(1, cwd, strlen(cwd));
		write(1, " > ", 3);
	}
	else
		write(1, "unknown > ", 10);
}*/

void write_prompt(void)
{
    char *cwd;
	cwd = absolut_path();
	
	printf("%s ", cwd);
    // if (getcwd(cwd, sizeof(cwd)) != NULL)
    // {
    // }
    // else
    // {
    //     printf("unknown > ");
    // }
}

void	prompt_loop_sub(char *line, char **token)
{
	t_cap	*head;
	t_cmd	*current;
	t_rdr	*tmp;
	size_t	i;

	token = split_tokens(line);
	if (!all_checks(token))
		return (exit_syntax(token), (void)0);
	put_env_arg(token);
	remove_quotes(token);
	head = parsing(token);
	printf("There are %d tok in the following command\n", head->tok);
	current = head->next;
	while (current)
	{
		i = 0;
		while (current->argv[i])
			printf("argv = %s\n", current->argv[i++]);
		printf("path = %s\n", current->cmd_path);
		tmp = current->redirs;
		while (tmp)
		{
			printf("\tfilename = %s\n", tmp->filename);
			printf("\ttype = %d\n", tmp->type);
			tmp = tmp->next;
		}
		current = current->next;
	}
	free_head_nodes(head);
	i = 0;
	while (token[++i]);
	free_tokens(token, i - 1);
}

void	prompt_loop(char **envp)
{
	char	*line;
	char	*origin;
	char	**token;
	(void)envp;

	write_prompt();
	line = readline("");
	while (line != NULL)
	{
		if (*line)
		{
			add_history(line);
			token = NULL;
			origin = line;
			prompt_loop_sub(line, token);
			if (isbuiltin(line))
				exec_builtins(line);
			else
				exec_cmd(line, envp);
		}
		free(origin);
		origin = NULL;
		write_prompt();
		line = readline("");
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

/*int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;

	prompt_loop(envp);
	return (0);
}*/	
