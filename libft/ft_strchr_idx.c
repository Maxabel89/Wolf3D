/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_idx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 13:27:37 by mporcher          #+#    #+#             */
/*   Updated: 2015/01/25 16:02:00 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchr_idx(const char *str, char c)
{
	int			i;
	char		*cpy;

	i = 0;
	cpy = (char *)str;
	while (cpy[i] != c)
	{
		if (cpy[i] == '\0')
			return (-1);
		i++;
	}
	return (cpy - str);
}
