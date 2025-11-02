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
	char	**token;
	size_t	i;

	token = split_tokens(line);
	if (!all_checks(token))
		return (exit_syntax(token), (void)0);
	put_env_arg(token, minishell);
	remove_quotes(token);
	head = parsing(token);
	minishell->cap = head;
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
			if (minishell->cap)
			{
				if (isbuiltin(minishell))
					exec_builtins(minishell);
				else
					exec_cmd(minishell);
				free_head_nodes(minishell->cap);
			}
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
	rl_clear_history();
}
