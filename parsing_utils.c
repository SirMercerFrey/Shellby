#include "minishell.h"

t_rdr	*create_redir(void)
{
	t_rdr	*new_redir;

	new_redir = (t_rdr *)(malloc(sizeof(t_rdr)));
	if (!new_redir)
		return (NULL);
	new_redir->type = 42;
	new_redir->filename = NULL;
	new_redir->next = NULL;
	return (new_redir);
}
	
t_cmd	*create_node(void)
{
	t_cmd	*new_node;

	new_node = (t_cmd *)(malloc(sizeof(t_cmd)));
	if (!new_node)
		return (NULL);
	new_node->argv = NULL;
	new_node->cmd_path = NULL;
	new_node->redirs = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_cap	*create_head(void)
{
	t_cap	*new_head;

	new_head = (t_cap *)(malloc(sizeof(t_cap)));
	if (!new_head)
		return (NULL);
	new_head->tok = 0;
	new_head->next = NULL;
	return (new_head);
}

void	free_redirs(t_rdr *tmp)
{
	t_rdr	*prev;

	while (tmp)
	{
		free(tmp->filename);
		prev = tmp;
		tmp = tmp->next;
		free(prev);
	}
}

void	free_head_nodes(t_cap *head)
{
	t_cmd	*current;
	t_cmd	*previous;
	t_rdr	*tmp;
	size_t	i;

	current = head->next;
	while (current)
	{
		i = 0;
		while (current->argv[i])
			free(current->argv[i++]);
		free(current->argv);
		free(current->cmd_path);
		tmp = current->redirs;
		free_redirs(tmp);
		previous = current;
		current = current->next;
		free(previous);
	}
	free(head);
}
