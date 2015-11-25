/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 16:30:59 by mporcher          #+#    #+#             */
/*   Updated: 2015/06/02 15:38:23 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_o(t_str *out, t_opt *opt, va_list *ap)
{
	t_ulong		o;
	char		*octal;
	t_str		tmp;

	if (opt->format->name == 'O')
		o = (long long int)(va_arg(*ap, unsigned long int));
	else
		o = get_unsigned_arg(opt, ap);
	if (o == 0 && opt->preci_set && opt->preci == 0)
	{
		if (ft_strchr(opt->flags, '#'))
			add_str(out, "0", 1, opt);
		else
			add_str(out, "", 0, opt);
		return ;
	}
	octal = ft_itobase(o, "01234567");
	ft_initstr(&tmp);
	if (ft_strchr(opt->flags, '#') && o > 0)
		ft_stradd_c(&tmp, '0');
	ft_stradd(&tmp, octal);
	pad_preci(&tmp, (ft_strchr(opt->flags, '#') && o > 0) ? 1 : 0, opt);
	add_str(out, tmp.content, tmp.length, opt);
	free(tmp.content);
	free(octal);
}
