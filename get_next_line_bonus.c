/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:54:40 by vaustin           #+#    #+#             */
/*   Updated: 2021/10/25 21:27:48 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*check_remain(char **remain, char **res)
{
	char	*backn_p;
	char	*tmp;

	backn_p = 0;
	if (*remain)
	{
		backn_p = ft_strchr(*remain, '\n');
		if (backn_p != 0)
		{
			*backn_p = '\0';
			*res = ft_strdup(*remain);
			tmp = *remain;
			*remain = ft_strdup(++backn_p);
			free(tmp);
		}
		else
		{
			*res = ft_strdup(*remain);
			free(*remain);
			*remain = 0;
		}
	}
	else
		*res = ft_strdup("");
	return (backn_p);
}

void	change_res(char **res, const char *str)
{
	char	*tmp;

	tmp = *res;
	*res = ft_strjoin(*res, str);
	free(tmp);
}

void	final_check_vars(int lbi, char *remain, char **res)
{
	if (lbi || ft_strlen(remain))
		change_res(&(*res), "\n");
	if (lbi || ft_strlen(remain) || ft_strlen(*res))
		return ;
	free(*res);
	*res = 0;
}

void	process_remain(char **remain, char **backn_p)
{
	if (*backn_p != 0)
	{
		**backn_p = '\0';
		if (*remain != 0)
		{
			free(*remain);
			*remain = 0;
		}
		*remain = ft_strdup(++(*backn_p));
	}
}

char	*get_next_line(int fd)
{
	static char	*remain[256];
	char		buf[BUFFER_SIZE + 1];
	int			last_byte_index;
	char		*backn_p;
	char		*res;

	if (read(fd, 0, 0) < 0)
		return (NULL);
	backn_p = check_remain(&remain[fd], &res);
	last_byte_index = 1;
	while (!backn_p && last_byte_index)
	{
		if (!backn_p)
			last_byte_index = read(fd, buf, BUFFER_SIZE);
		buf[last_byte_index] = '\0';
		backn_p = ft_strchr(buf, '\n');
		process_remain(&remain[fd], &backn_p);
		change_res(&res, buf);
	}
	final_check_vars(last_byte_index, remain[fd], &res);
	return (res);
}
