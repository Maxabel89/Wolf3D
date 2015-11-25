/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 14:09:22 by mporcher          #+#    #+#             */
/*   Updated: 2015/06/01 18:19:37 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countseg(char const *s, char c)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			j++;
			i++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (j);
}

static char		*ft_addseg(size_t *i, char const *s, char c)
{
	size_t		len;
	size_t		j;
	char		*seg;

	len = *i;
	j = 0;
	while (s[len] && s[len] != c)
		len++;
	seg = ft_strnew(len - *i);
	if (seg)
	{
		while (*i < len)
		{
			seg[j] = s[*i];
			j++;
			*i += 1;
		}
		return (seg);
	}
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		o;
	size_t		*i;
	size_t		j;
	char		**str;

	o = 0;
	i = &o;
	j = 0;
	str = NULL;
	if (s)
		str = (char **)malloc(sizeof(char *) * (ft_countseg(s, c) + 1));
	if (str)
	{
		while (j < ft_countseg(s, c))
		{
			while (s[*i] == c)
				*i += 1;
			if (s[*i] != c && s[*i])
				str[j++] = ft_addseg(i, s, c);
		}
		str[j] = 0;
		return (str);
	}
	return (0);
}
