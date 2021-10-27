/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:57:49 by vaustin           #+#    #+#             */
/*   Updated: 2021/10/25 21:18:55 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const	char *s);
char	*get_next_line(int fd);
void	process_remain(char **remain, char **backn_p);
void	final_check_vars(int lbi, char *remain, char **res);
void	change_res(char **res, const char *str);
char	*check_remain(char **remain, char **res);

#endif