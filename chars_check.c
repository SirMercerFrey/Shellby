#include "minishell.h"

int		metachars(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

int		quotes(char c)
{
	return (c == '\'' || c == '"');
}


int		spaces(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int		is_redir(char c)
{
	return (c == '>' || c == '<');
}

int	are_redir(char *str)
{
	if (!str)
		return (0);
	if (!ft_strcmp(str, "<"))
		return (1);
	if (!ft_strcmp(str, ">"))
		return (1);
	if (!ft_strcmp(str, "<<"))
		return (1);
	if (!ft_strcmp(str, ">>"))
		return (1);
	return (0);
}
