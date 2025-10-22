/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 22:35:51 by mjustine          #+#    #+#             */
/*   Updated: 2025/09/23 22:35:53 by mjustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*check_direct_path(char *cmd)
{
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
	}
	return (NULL);
}

char	*get_path_variable(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*search_in_paths(char *cmd, char **paths)
{
	char	*tmp;
	char	*full_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full_path, X_OK) == 0)
		{
			ft_free_split(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	ft_free_split(paths);
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	char	*direct;
	char	*path_var;
	char	**paths;

	direct = check_direct_path(cmd);
	if (direct)
		return (direct);
	path_var = get_path_variable(envp);
	if (!path_var)
		return (NULL);
	paths = ft_split_char(path_var, ':');
	if (!paths)
		return (NULL);
	return (search_in_paths(cmd, paths));
}

char *absolut_path(void)
{
    char *full_path = getcwd(NULL, 0);
    char *last_slash = ft_strrchr(full_path, '/');
    char *folder_name;
    char *result;

    if (last_slash && *(last_slash + 1))
        folder_name = last_slash + 1;
    else
        folder_name = full_path;

    result = ft_strjoin(folder_name, " > ");
    free(full_path);
    return result;
}