/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:34:46 by mporcher          #+#    #+#             */
/*   Updated: 2014/11/08 17:09:53 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void		ft_neg_limit(char *nbr)
{
	int		i;

	i = 0;
	while (i <= 11)
	{
		ft_putchar(nbr[i]);
		i++;
	}
}

void				ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_neg_limit("-2147483648");
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar('0' + nb);
}
