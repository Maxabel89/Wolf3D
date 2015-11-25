/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 16:43:29 by mporcher          #+#    #+#             */
/*   Updated: 2015/06/02 15:38:20 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			flag_p(t_str *out, t_opt *opt, va_list *ap)
{
	char	*hex;
	t_str	tmp;

	ft_initstr(&tmp);
	ft_str_ins(&tmp, "0x", 0);
	if (!opt->preci_set || opt->preci != 0)
	{
		hex = ft_itobase((t_ulong)(va_arg(*ap, void *)), "0123456789abcdef");
		ft_stradd(&tmp, hex);
		pad_preci(&tmp, 2, opt);
		free(hex);
	}
	add_str(out, tmp.content, tmp.length, opt);
	free(tmp.content);
}
