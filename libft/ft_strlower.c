/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 15:20:04 by mporcher          #+#    #+#             */
/*   Updated: 2015/01/22 15:20:18 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			ft_strupper(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && *str <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
}