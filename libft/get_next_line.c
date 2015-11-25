/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 14:34:42 by mporcher          #+#    #+#             */
/*   Updated: 2015/06/13 21:53:49 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *s1, int n, int *size_line)
{
	char	*str;

	if (s1)
	{
		*size_line = n;
		str = (char *)malloc(sizeof(char) * n + 1);
		str = ft_memcpy(str, s1, n);
		str[n] = '\0';
		return (str);
	}
	return (NULL);
}

static char	*ft_strnjoin(char *s1, char *s2, int n, int *size_line)
{
	char	*str;

	if (s1 && s2)
	{
		str = (char *)malloc(sizeof(char) * (*size_line + n + 1));
		ft_memcpy(str, s1, *size_line);
		free(s1);
		ft_memcpy(&str[*size_line], s2, n);
		str[*size_line + n] = '\0';
		*size_line += n;
		return (str);
	}
	return (NULL);
}

int			get_next_line(int const fd_const, char **line)
{
	static	t_gnl	gnl[64] = {{{0}, 0, 0, 0}};
	t_norme			n;

	if (!(n.n = NULL) && (!line || fd_const < 0))
		return (-1);
	n.f = fd_const % 64;
	*line = NULL;
	while (!n.n)
	{
		if (gnl[n.f].i == gnl[n.f].r && !(gnl[n.f].i = 0))
		{
			if ((gnl[n.f].r = read(fd_const, gnl[n.f].buf, BUFF_SIZE)) <= 0)
			{
				n.t = gnl[n.f].r;
				gnl[n.f].r = 0;
				return (*line ? 1 : n.t);
			}
		}
		n.n = ft_memchr(&gnl[n.f].buf[gnl[n.f].i], 10, gnl[n.f].r - gnl[n.f].i);
		n.l = (n.n) ? n.n - &gnl[n.f].buf[gnl[n.f].i] : gnl[n.f].r - gnl[n.f].i;
		*line = (*line) ? ft_strnjoin(*line, &gnl[n.f].buf[gnl[n.f].i], n.l,
		&gnl[n.f].s) : ft_strndup(&gnl[n.f].buf[gnl[n.f].i], n.l, &gnl[n.f].s);
		gnl[n.f].i = (n.n) ? gnl[n.f].i + n.l + 1 : gnl[n.f].r;
	}
	return (1);
}
