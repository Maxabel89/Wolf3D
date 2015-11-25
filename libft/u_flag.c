/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 16:53:28 by mporcher          #+#    #+#             */
/*   Updated: 2015/06/02 15:38:50 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		add_ulong(char *str, int i, t_ulong nb, t_opt *opt)
{
	const int		len = i;

	while (i > 0 && nb != 0)
	{
		str[i--] = '0' + (nb % 10);
		if (((len - i + 1) % 4) == 0 && ft_strchr(opt->flags, '\''))
			str[i--] = ' ';
		nb /= 10;
	}
	return (i);
}

static int		padding_u(t_opt *opt)
{
	int		pad;

	if (opt->preci_set)
		pad = MIN(opt->width, opt->preci) + 1;
	else
		pad = opt->width + 1;
	return (pad);
}

static t_ulong	get_nb(t_opt *opt, va_list *ap)
{
	t_ulong		nb;

	if (opt->format->name != 'U')
		nb = get_unsigned_arg(opt, ap);
	else
		nb = (t_ulong)(va_arg(*ap, unsigned long int));
	return (nb);
}

void			flag_u(t_str *out, t_opt *opt, va_list *ap)
{
	int				len;
	char			*str;
	int				i;
	int				pad;
	t_ulong			nb;

	len = MAX(40, MAX(opt->width, opt->preci));
	str = (char *)malloc(sizeof(char) * len);
	if (str == NULL)
		exit (2);
	nb = get_nb(opt, ap);
	i = len - 1;
	if (nb == 0 && (!opt->preci_set || opt->preci != 0))
		str[i--] = '0';
	else
		i = add_ulong(str, i, nb, opt);
	pad = padding_u(opt);
	if (ft_strchr(opt->flags, '0'))
		while ((len - i) < pad)
			str[i--] = '0';
	if (opt->preci_set)
		while ((len - i - 1) < opt->preci)
			str[i--] = '0';
	add_str(out, str + 1 + i, len - 1 - i, opt);
}
