#include "minishell.h"

void	add_arg(char ***argv, char *word)
{
	size_t	count;
	size_t	i;
	char	**new_argv;

	count = 0;
	while (*argv && (*argv)[count])
		++count;
	new_argv = malloc(sizeof(char *) * (count + 2));
	i = 0;
	while (i < count)
	{
		new_argv[i] = (*argv)[i];
		++i;
	}
	new_argv[count] = ft_strdup(word);
	new_argv[count + 1] = NULL;
	free(*argv);
	*argv = new_argv;
}

void	handle_direction(char **token, t_cmd *node, int *n)
{
	t_rdr	*new;
	t_rdr	*tmp;

	new = create_redir();
	tmp = node->redirs;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		node->redirs = new;
	if (!ft_strcmp(token[*n], "<"))
		new->type = 0;
	else if (!ft_strcmp(token[*n], ">"))
		new->type = 1;
	else if (!ft_strcmp(token[*n], "<<"))
		new->type = 2;
	else if (!ft_strcmp(token[*n], ">>"))
		new->type = 3;
	new->filename = ft_strdup(token[++*n]);
}

void	parsing_loop(char **token, t_cmd *node, int *n)
{
	t_cmd	*new;

	while (token[*n])
	{
		if (!ft_strcmp(token[*n], "|"))
		{
			new = create_node();
			node->next = new;
			node = new;
		}
		else if (are_redir(token[*n])) 
			handle_direction(token, node, n);
		else
			add_arg(&node->argv, token[*n]);
		++*n;
	}
}


t_cap *parsing(char **token)
{
	t_cmd	*node;
	t_cap	*head;
	int		nbr_tok;

	head = create_head();
	if (!head)
		return (NULL);
	node = create_node();
	if (!node)
	{
		free(head);
		return (NULL);
	}
	head->next = node;
	nbr_tok = 0;
	parsing_loop(token, node, &nbr_tok);
	head->tok = nbr_tok;
	return (head);
}
