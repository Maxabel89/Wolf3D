/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:21:18 by mporcher          #+#    #+#             */
/*   Updated: 2014/11/05 19:37:03 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strstr(const char *s1, const char *s2)
{
	size_t len;

	if (*s2 == '\0')
		return ((char *)s1);
	len = ft_strlen(s2);
	while ((s1 = ft_strchr(s1, *s2)) && s1 != '\0')
	{
		if (ft_strncmp(s1, s2, len) == 0)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
