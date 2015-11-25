/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tools4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 17:34:30 by mporcher          #+#    #+#             */
/*   Updated: 2015/06/02 15:38:46 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strput(t_str *str)
{
	write(1, str->content, str->length);
	return (str->length);
}

void			ft_stradd_i(t_str *str, int nbr)
{
	char			*nb;
	unsigned int	i;

	nb = (char *)malloc(sizeof(char) * 11);
	if (nb == NULL)
		return ;
	i = 11;
	if (nbr < 0)
		nb[0] = '-';
	else
		nb[0] = '+';
	if (nbr <= 0)
	{
		nb[--i] = '0' - (nbr % 10);
		nbr /= -10;
	}
	while (nbr != 0)
	{
		nb[--i] = '0' + (nbr % 10);
		nbr /= 10;
	}
	if (nb[0] == '-')
		nb[--i] = '-';
	ft_stradd_l(str, nb + i, 11 - i);
}

void			add_nchar(t_str *out, char c, int len, t_opt *opt)
{
	char			*str;

	str = (char *)malloc(sizeof(char) * len);
	if (str == NULL)
		exit(2);
	ft_memset(str, c, len);
	add_str(out, str, len, opt);
}
