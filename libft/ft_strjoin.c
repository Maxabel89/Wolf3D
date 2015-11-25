/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:24:52 by mporcher          #+#    #+#             */
/*   Updated: 2014/11/07 16:53:21 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*jnd;
	char	*jndcpy;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	jnd = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (jnd == NULL)
		return (NULL);
	jndcpy = jnd;
	while (*s1 != '\0')
		*jndcpy++ = *s1++;
	while (*s2 != '\0')
		*jndcpy++ = *s2++;
	*jndcpy = '\0';
	return (jnd);
}
