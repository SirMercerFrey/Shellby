#include "minishell.h"

void	remove_outer_quotes_inplace(char *str)
{
	int		in_single_quote;
	int		in_double_quote;
	size_t	read;
	size_t	write;

	in_single_quote = 0;
	in_double_quote = 0;
	read = 0;
	write = 0;
	while (str[read])
	{
		if (str[read] == '\'' && in_double_quote == 0)	
		{
			in_single_quote = !in_single_quote;
			++read;
		}
		else if (str[read] == '"' && in_single_quote == 0)
		{
			in_double_quote = !in_double_quote;
			++read;
		}
		else
			str[write++] = str[read++];
	}
	str[write] = '\0';
}

void	remove_quotes(char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		remove_outer_quotes_inplace(argv[i]);
		++i;
	}
}
