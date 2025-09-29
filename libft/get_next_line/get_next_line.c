/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjustine <mjustine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:17:29 by mjustine          #+#    #+#             */
/*   Updated: 2025/06/03 12:26:36 by mjustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join_free(char *s1, const char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

char	*check_stash(char **stash, char *str)
{
	char	*tmp;
	int		nl_pos;

	if (*stash)
	{
		if (ft_strchr(*stash, '\n'))
		{
			nl_pos = ft_strchr(*stash, '\n') - *stash;
			tmp = ft_substr(*stash, 0, nl_pos + 1);
			str = join_free(str, tmp);
			free(tmp);
			if (!str)
				return (NULL);
			tmp = ft_substr(*stash, nl_pos + 1, ft_strlen(*stash) - nl_pos - 1);
			free(*stash);
			*stash = tmp;
			return (str);
		}
		str = join_free(str, *stash);
		free(*stash);
		*stash = NULL;
		if (!str)
			return (NULL);
	}
	return (str);
}

char	*split_str_stash(char *buff, char *str, char **stash, int rd)
{
	char	*tmp;
	int		nl_pos;

	nl_pos = ft_strchr(buff, '\n') - buff;
	tmp = ft_substr(buff, 0, nl_pos + 1);
	if (!tmp)
		return (free(str), NULL);
	str = join_free(str, tmp);
	free(tmp);
	if (!str)
		return (NULL);
	tmp = ft_substr(buff, nl_pos + 1, rd - nl_pos - 1);
	if (!tmp)
		return (free(str), NULL);
	free(*stash);
	*stash = tmp;
	return (str);
}

char	*get_a_line(int fd, char *str, char **stash)
{
	char	*buff;
	int		rd;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (free(str), NULL);
	rd = read(fd, buff, BUFFER_SIZE);
	while (rd > 0)
	{
		buff[rd] = '\0';
		if (ft_strchr(buff, '\n'))
		{
			str = split_str_stash(buff, str, stash, rd);
			break ;
		}
		str = join_free(str, buff);
		rd = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	if (rd == -1)
		return (free(str), NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	str = check_stash(&stash, str);
	if (!str)
		return (NULL);
	if (!ft_strchr(str, '\n'))
		str = get_a_line(fd, str, &stash);
	if (!str || str[0] == '\0')
		return (free(str), NULL);
	return (str);
}
/*
int	main(void)
{
	int		fd;
	char	*line;
	
	fd = open("test_gnl.txt", O_RDONLY);
	if (fd == -1)
	return (1);
	while ((line = get_next_line(fd)))
	{
		printf("Line : %s", line);
		free(line);
	}
	close(fd);
	return (0);
}
*/
