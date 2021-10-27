/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:54:44 by vaustin           #+#    #+#             */
/*   Updated: 2021/10/25 21:19:11 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		i;
	int		s1_size;

	i = 0;
	s1_size = 0;
	while (s1[s1_size] != '\0')
		s1_size++;
	res = malloc(s1_size + 1);
	if (res == 0)
		return (0);
	while (i < s1_size)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == (char) c)
		return ((char *) &s[i]);
	return (0);
}

static void	process_vars(int *len, int *i, int *j)
{
	*len = *len + *i;
	*i = 0;
	*j = 0;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*res;
	int		i;
	int		j;

	if (s1 == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0')
		i++;
	len = i;
	i = 0;
	while (s2[i] != '\0')
		i++;
	process_vars(&len, &i, &j);
	res = malloc(sizeof(char) * (len + 1));
	if (res == 0)
		return (0);
	while (s1[i] != '\0')
		res[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

size_t	ft_strlen(const	char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
