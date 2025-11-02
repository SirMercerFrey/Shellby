#include "minishell.h"

char	*get_prompt(void)
{
    char 	*cwd;
	char	*prompt;

	cwd = NULL;
    cwd = getcwd(NULL, 0); 
	if (cwd != NULL)
    {
		prompt = ft_strjoin(cwd, " > ");
		free(cwd);
		return (prompt);
    }
    else
    {
        printf("unknown > ");
		return (NULL);
    }
}

void	prompt_loop_sub(char *line, t_shell *minishell)
{
	t_cap	*head;
	t_cmd	*current;
	t_rdr	*tmp;
	char	**token;
	size_t	i;

	token = split_tokens(line);
	if (!all_checks(token))
		return (exit_syntax(token), (void)0);
	put_env_arg(token, minishell->envp);
	remove_quotes(token);
	head = parsing(token);
	printf("There are %d tok in the following command\n", head->tok);
	minishell->cap = head;
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

void	prompt_loop(t_shell *minishell)
{
	char	*line;
	char	*origin;
	char	*prompt;

	prompt = get_prompt();
	line = readline(prompt);
	while (line != NULL)
	{
		if (*line)
		{
			add_history(line);
			origin = line;
			prompt_loop_sub(line, minishell);
			free(origin);
			origin = NULL;
		}
		else
			free(line);
		free(prompt);
		prompt = get_prompt();
		line = readline(prompt);
	}
	free(prompt);
}
