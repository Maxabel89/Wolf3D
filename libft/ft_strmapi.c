/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:36:24 by mporcher          #+#    #+#             */
/*   Updated: 2014/11/09 13:19:32 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	int				len;
	char			*map;
	char			*scpy;

	scpy = (char *)s;
	len = 0;
	if (s && f)
	{
		if (scpy != NULL)
			len = ft_strlen(scpy);
		map = (char *)malloc(len + 1);
		i = 0;
		if (scpy != NULL && f != NULL)
		{
			while (scpy[i])
			{
				map[i] = f(i, scpy[i]);
				i++;
			}
		}
		map[i] = '\0';
		return (map);
	}
	return (NULL);
}
