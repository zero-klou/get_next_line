/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:54:40 by vaustin           #+#    #+#             */
/*   Updated: 2021/10/25 21:21:34 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*remain;
	char		buf[BUFFER_SIZE + 1];
	int			last_byte_index;
	char		*backn_p;
	char		*res;

	backn_p = check_remain(&remain, &res);
	last_byte_index = 1;
	while (!backn_p && last_byte_index)
	{
		if (!backn_p)
			last_byte_index = read(fd, buf, BUFFER_SIZE);
		if (last_byte_index == -1)
		{
			free(res);
			return (0);
		}
		buf[last_byte_index] = '\0';
		backn_p = ft_strchr(buf, '\n');
		process_remain(&remain, &backn_p);
		change_res(&res, buf);
	}
	final_check_vars(last_byte_index, remain, &res);
	return (res);
}
