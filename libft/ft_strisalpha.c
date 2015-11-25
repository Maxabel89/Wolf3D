/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 09:48:11 by mporcher          #+#    #+#             */
/*   Updated: 2015/05/27 09:49:22 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strisalpha(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha((int)str[i]))
			return (1);
		i++;
	}
	return (0);
}
