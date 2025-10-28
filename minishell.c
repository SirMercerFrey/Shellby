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

t_cmd	*prompt_loop_sub(char *line, char **envp)
{
	char **tokens;
	t_cap	*head;
	t_cmd	*current;
	t_rdr	*tmp;
	size_t	i;

	tokens = split_tokens(line);
	if (!all_checks(tokens))
		return (exit_syntax(tokens), NULL);
	put_env_arg(tokens, envp);
	remove_quotes(tokens);
	head = parsing(tokens);
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
    t_cmd *cmds = head->next;
	// free_head_nodes(head);
	i = 0;
	while (tokens[++i])
		free_tokens(tokens, i - 1);

	return cmds;
}

void prompt_loop(char **envp)
{
    char *line;
    char *prompt;
    t_cmd *cmds;

    while (1)
    {
        prompt = absolut_path();
        line = readline(prompt);
        free(prompt);

        if (!line)
            break;

        if (*line)
        {
            add_history(line);
            cmds = prompt_loop_sub(line, envp);
            if (cmds)
            {
                if (isbuiltin(cmds))
                    exec_builtins(cmds, &envp);
                else
                    exec_cmd(cmds, envp);
                // free_cmd_list(cmds);
            }
        }
        free(line);
    }
}

int isbuiltin(t_cmd *cmd)
{
    if (ft_strcmp(cmd->argv[0], "pwd") == 0)
        return (1);
    if (ft_strcmp(cmd->argv[0], "cd") == 0)
        return (1);
    if (ft_strcmp(cmd->argv[0], "export") == 0)
        return (1);
    if (ft_strcmp(cmd->argv[0], "unset") == 0)
        return (1);
    if (ft_strcmp(cmd->argv[0], "env") == 0)
        return (1);
    return (0);
}

void    exec_builtins(t_cmd *cmd, char ***envp)
{
    if (ft_strncmp(cmd->argv[0], "pwd", 3) == 0)
		builtin_pwd(cmd);
	else if (ft_strncmp(cmd->argv[0], "cd", 2) == 0)
		builtin_cd(cmd, envp);
	else if ((ft_strncmp(cmd->argv[0], "export", 6) == 0))
		builtin_export(cmd, envp);
	else if ((ft_strncmp(cmd->argv[0], "unset", 5) == 0))
		builtin_unset(cmd, envp);
	else if ((ft_strncmp(cmd->argv[0], "env", 3) == 0))
		builtin_env(envp);
}

void	exec_cmd(t_cmd *cmd, char **envp)
{
	pid_t	pid;
	int		status;

	cmd->cmd_path = find_path(cmd->argv[0], envp);
	printf("ALLLLO%s\n", cmd->cmd_path);
	pid = fork();
	if (pid == 0)
	{
		if (!cmd->cmd_path)
			printf("Command not found: %s\n", cmd->argv[0]);
		else
		{
			execve(cmd->cmd_path, cmd->argv, envp);
			perror("execve");
		}
		ft_free_split(cmd->argv);
		free(cmd->cmd_path);
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
