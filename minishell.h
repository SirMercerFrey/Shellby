/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 22:37:14 by mjustine          #+#    #+#             */
/*   Updated: 2025/09/23 22:37:16 by mjustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

void	prompt_loop(char *line, char **envp);
char	*check_direct_path(char *cmd);
void	ft_free_split(char **arr);
char	*get_path_variable(char **envp);
char	*search_in_paths(char *cmd, char **paths);
char	*find_path(char *cmd, char **envp);
void	exec_cmd(char *cmd, char **envp);

#endif
