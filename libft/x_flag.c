/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 13:57:51 by mporcher          #+#    #+#             */
/*   Updated: 2015/06/02 15:38:54 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			flag_x(t_str *out, t_opt *opt, va_list *ap)
{
	char			*hex;
	t_ulong			x;
	t_str			tmp;

	x = get_unsigned_arg(opt, ap);
	if (x == 0 && opt->preci_set && opt->preci == 0)
	{
		add_str(out, "", 0, opt);
		return ;
	}
	if (opt->format->name == 'x')
		hex = ft_itobase(x, "0123456789abcdef");
	else
		hex = ft_itobase(x, "0123456789ABCDEF");
	ft_initstr(&tmp);
	if (ft_strchr(opt->flags, '#') && x > 0)
		ft_stradd(&tmp, (opt->format->name == 'x') ? "0x" : "0X");
	ft_stradd(&tmp, hex);
	pad_preci(&tmp, (ft_strchr(opt->flags, '#') && x > 0) ? 2 : 0, opt);
	add_str(out, tmp.content, tmp.length, opt);
	free(tmp.content);
	free(hex);
}
