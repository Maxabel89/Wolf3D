/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 14:18:19 by mporcher          #+#    #+#             */
/*   Updated: 2015/06/02 15:38:48 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_stradd_int(t_str *str, double nbr)
{
	int				tmp;
	int				length;

	if (nbr < 0)
		length = 2;
	else
		length = 1;
	while ((nbr /= 10) > 1)
		length++;
	if (!ft_strext(str, length))
		return ;
	if (nbr < 0)
		str->content[str->length++] = '-';
	length += str->length;
	while (str->length < length)
	{
		nbr *= 10;
		tmp = (int)nbr;
		str->content[str->length++] = '0' + tmp;
		nbr -= tmp;
	}
}

static void		fix_preci(t_str *str)
{
	int				i;

	i = str->length;
	while (str->content[--i] == '9')
		str->content[i] = '0';
	str->content[i]++;
}

static void		check_stradd_d(t_str *str, double d, int preci)
{
	if (preci <= 0)
		ft_stradd_int(str, d + 0.5);
	else
		ft_stradd_int(str, d);
	if (preci <= 0)
		return ;
	if (!ft_strext(str, preci + 1))
		return ;
}

void			ft_stradd_d(t_str *str, double d, int preci)
{
	int				i;
	int				tmp;

	check_stradd_d(str, d, preci);
	ft_stradd_c(str, '.');
	d -= (int)d;
	i = -1;
	while (i++ < preci)
	{
		d *= 10;
		if ((i + 1) >= preci)
			d += 0.5;
		tmp = (int)d;
		if (tmp >= 10)
		{
			tmp = tmp % 10;
			fix_preci(str);
		}
		str->content[str->length++] = '0' + tmp;
		d -= tmp;
	}
}

char			*ft_itobase(t_ulong nb, const char *base)
{
	int				base_len;
	char			*str;
	int				i;
	t_ulong			tmp;

	base_len = ft_strlen(base);
	if (nb == 0 || base_len == 0)
		return (ft_strdup("0"));
	tmp = nb;
	i = 1;
	while ((tmp /= base_len) != 0)
		i++;
	str = (char *)malloc(sizeof(char) * i + 1);
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	tmp = nb;
	while (--i >= 0)
	{
		str[i] = base[tmp % base_len];
		tmp /= base_len;
	}
	return (str);
}
