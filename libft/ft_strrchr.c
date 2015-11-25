/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:55:03 by mporcher          #+#    #+#             */
/*   Updated: 2014/11/09 10:53:52 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	a;
	int		i;
	char	*ptr;

	i = 0;
	a = (char)c;
	ptr = (char *)s;
	while (ptr[i] != '\0')
		i++;
	if (a == '\0')
		return (&ptr[i]);
	while (i >= 0)
	{
		if (ptr[i] == a)
			return (&ptr[i]);
		i--;
	}
	return (0);
}
