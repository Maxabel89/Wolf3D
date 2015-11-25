/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:16:13 by mporcher          #+#    #+#             */
/*   Updated: 2014/11/08 14:13:39 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*strmd;
	char const	*end;
	char const	*idx;

	idx = NULL;
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (!(*s == ' ' || *s == '\n' || *s == '\t'))
		{
			idx = (idx == NULL) ? s : idx;
			end = s;
		}
		s++;
	}
	if (idx == NULL)
		return (ft_strnew(0));
	if ((strmd = (char *)malloc(sizeof(char) * (end - idx + 2))) == NULL)
		return (NULL);
	s = idx;
	while (s <= end)
		*strmd++ = *s++;
	*strmd = '\0';
	return (strmd - (end - idx + 1));
}
