/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:59:03 by mporcher          #+#    #+#             */
/*   Updated: 2015/04/03 16:48:06 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*map;
	char	*ss;

	ss = (char *)s;
	if (s && f)
	{
		if (ss == NULL)
			return (NULL);
		i = ft_strlen(ss);
		map = (char *)malloc(i + 1);
		i = 0;
		if (ss != NULL && f != NULL)
		{
			while (ss[i])
			{
				map[i] = f(ss[i]);
				i++;
			}
		}
		map[i] = '\0';
		return (map);
	}
	return (0);
}
