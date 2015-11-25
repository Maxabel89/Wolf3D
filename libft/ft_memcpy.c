/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:00:03 by mporcher          #+#    #+#             */
/*   Updated: 2014/11/05 19:32:55 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int			i;
	char		*dstcpy;
	const char	*srccpy;

	dstcpy = (char *)dst;
	srccpy = (const char *)src;
	i = 0;
	while (n > 0)
	{
		dstcpy[i] = srccpy[i];
		i++;
		n--;
	}
	return (dst);
}
