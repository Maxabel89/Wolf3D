/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:29:41 by mporcher          #+#    #+#             */
/*   Updated: 2014/11/05 19:32:32 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*f1;
	unsigned char	*f2;

	i = 0;
	f1 = (unsigned char *)s1;
	f2 = (unsigned char *)s2;
	while (i < n)
	{
		if (f1[i] != f2[i])
			return (f1[i] - f2[i]);
		else
			i++;
	}
	return (0);
}
