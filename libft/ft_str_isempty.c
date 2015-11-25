/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isempty.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 18:00:32 by mporcher          #+#    #+#             */
/*   Updated: 2015/06/13 21:46:36 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_isempty(char const *str, char c)
{
	int		i;

	i = ft_strlen(str);
	i--;
	while (i != 0)
	{
		if (str[i] != c)
			break ;
		i--;
	}
	return (i);
}
