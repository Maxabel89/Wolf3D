/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:56:13 by mporcher          #+#    #+#             */
/*   Updated: 2014/11/06 14:40:14 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*dstcpy;
	const char	*srccpy;

	i = 0;
	dstcpy = (char *)dst;
	srccpy = (const char *)src;
	while (i < n && (i == 0 || srccpy[i - 1] != c))
	{
		dstcpy[i] = srccpy[i];
		i++;
	}
	if (i > 0 && srccpy[i - 1] == c)
	{
		return (dstcpy + i);
	}
	else
		return (NULL);
}
