/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 16:04:44 by mporcher          #+#    #+#             */
/*   Updated: 2014/11/08 16:28:31 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_itlen(int n)
{
	if (n < 0)
		return (1 + ft_itlen(-n));
	if (n < 10)
		return (1);
	return (1 + ft_itlen(n / 10));
}

char			*ft_itoa(int n)
{
	int		len;
	int		neg;
	int		i;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = (n < 0 ? 1 : 0);
	len = ft_itlen(n);
	str = (char*)malloc(sizeof(*str) * (len + 1));
	if (str)
	{
		n = (n < 0 ? -n : n);
		i = len - 1;
		while (i >= neg)
		{
			str[i] = (n % 10) + 48;
			n /= 10;
			i--;
		}
		if (neg)
			str[0] = '-';
		str[len] = '\0';
	}
	return (str);
}
