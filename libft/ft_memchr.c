/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:04:41 by mporcher          #+#    #+#             */
/*   Updated: 2014/11/05 19:32:14 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*f;
	size_t			i;

	i = 0;
	f = (unsigned char *)s;
	while (i < n)
	{
		if (*f != (unsigned char)c)
		{
			f++;
			i++;
		}
		else
			return (f);
	}
	return (NULL);
}
