#include "minishell.h"

int		check_pipes(char **token)
{
	size_t	i;

	if (!ft_strcmp(token[0], "|"))
		return (0);
	i = 0;
	while (token[i] && token[i + 1])
	{
		if (!ft_strcmp(token[i], "|") && !ft_strcmp(token[i], token[i + 1]))
			return (0);
		++i;
	}
	if (!ft_strcmp(token[i], "|"))
		return (0);
	return (1);
}

int		check_redirections(char **token)
{
	size_t	i;

	i = 0;
	while (token[i] && token[i + 1])
	{
		if (is_redir(token[i][0]) && is_redir(token[i + 1][0]))
			return (0);
		++i;
	}
	if (is_redir(token[i][0]))
		return (0);
	return (1);
}

int		check_quotes(char **token)
{
	int		in_single_quote;
	int		in_double_quote;
	size_t	i;
	size_t	j;

	in_single_quote = 0;
	in_double_quote = 0;
	i = 0;
	while (token[i])
	{
		j = 0;
		while (token[i][j])
		{
			if (token[i][j] == '\'' && in_double_quote == 0)
				in_single_quote = !in_single_quote;
			else if (token[i][j] == '"' && in_single_quote == 0)
				in_double_quote = !in_double_quote;
			++j;
		}
		++i;
	}
	return (in_single_quote == 0 && in_double_quote == 0);
}

int		all_checks(char **token)
{
	if (!check_pipes(token))
		return (0);
	if (!check_redirections(token))
		return (0);
	if (!check_quotes(token))
		return (0);
	return (1);
}

void	exit_syntax(char **token)
{
	int		i;
//	char	*red;

//	red = "\033[0;31m";
//	write(2, red, ft_strlen(red));
	write(2, "Syntax error.\n", ft_strlen("Syntax error.\n"));
//	write(2, red, ft_strlen(red));
	i = 0;
	while (token[++i]);
	free_tokens(token, i - 1);
}
