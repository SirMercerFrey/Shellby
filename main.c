#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	t_shell		*minishell;

	minishell = create_shell(envp);	
	if (!minishell)
		return (1);
	print_banner_start();
	prompt_loop(minishell);
	free_shell(minishell);
	print_banner_end();
	return (0);
}


//valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=readline.supp ./minishell
