/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 17:12:45 by mporcher          #+#    #+#             */
/*   Updated: 2015/06/02 15:38:29 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				add_lng(char *str, int i, long long int nb, t_opt *opt)
{
	const int	len = i;

	while (i > 0 && nb != 0)
	{
		if (nb < 0)
			str[i--] = '0' + -(nb % 10);
		else
			str[i--] = '0' + nb % 10;
		if (((len - i + 1) % 4) == 0 && ft_strchr(opt->flags, '\''))
			str[i--] = ' ';
		nb /= 10;
	}
	return (i);
}

static int				padding_d(t_opt *opt, long long int nb)
{
	int		pad;

	if (opt->preci_set)
	{
		if ((nb < 0 || ft_strchr(opt->flags, '+')
			|| ft_strchr(opt->flags, ' ')) && !opt->preci_set)
			pad = MIN(opt->width, opt->preci) + 0;
		else
			pad = MIN(opt->width, opt->preci) + 1;
	}
	else
	{
		if ((nb < 0 || ft_strchr(opt->flags, '+')
			|| ft_strchr(opt->flags, ' ')) && !opt->preci_set)
			pad = opt->width + 0;
		else
			pad = opt->width + 1;
	}
	return (pad);
}

static long long int	get_nb(t_opt *opt, va_list *ap)
{
	long long int		nb;

	if (opt->format->name == 'D')
		nb = (long long int)(va_arg(*ap, long int));
	else
		nb = get_arg(opt, ap);
	return (nb);
}

void					flag_d(t_str *out, t_opt *opt, va_list *ap)
{
	int				len;
	char			*str;
	int				i;
	long long int	nb;

	len = MAX(40, MAX(opt->width, opt->preci));
	str = (char *)malloc(sizeof(char) * len);
	if (str == NULL)
		exit (2);
	i = len - 1;
	nb = get_nb(opt, ap);
	if (nb == 0 && (!opt->preci_set || opt->preci != 0))
		str[i--] = '0';
	else
		i = add_lng(str, len - 1, nb, opt);
	if (ft_strchr(opt->flags, '0') && !ft_strchr(opt->flags, '-'))
		while ((len - i) < padding_d(opt, nb))
			str[i--] = '0';
	while (opt->preci_set && (len - i - 1) < opt->preci)
		str[i--] = '0';
	if (nb < 0 || ft_strchr(opt->flags, '+'))
		str[i--] = (nb < 0) ? '-' : '+';
	else if (ft_strchr(opt->flags, ' '))
		str[i--] = ' ';
	add_str(out, str + 1 + i, len - 1 - i, opt);
}
