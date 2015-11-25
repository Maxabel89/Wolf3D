/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 16:50:04 by mporcher          #+#    #+#             */
/*   Updated: 2015/06/02 15:15:20 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		s_null(t_str *out, t_opt *opt)
{
	if (opt->preci_set && opt->preci < 6)
	{
		opt->preci = opt->width;
		if (ft_strchr(opt->flags, '0'))
			add_nchar(out, '0', opt->width, opt);
		else
			add_nchar(out, ' ', opt->width, opt);
	}
	else
		add_str(out, "(null)", 6, opt);
	return (1);
}

static void		flag_ws(t_str *out, t_opt *opt, wchar_t *wstr)
{
	int		len;
	char	*str;
	int		length;

	len = ft_wstrlen(wstr) * 4;
	str = (char *)malloc(sizeof(char) * len);
	if (wstr == NULL && s_null(out, opt))
		return ;
	if ((opt->preci_set && len > opt->preci))
		length = ft_wstrnconv(str, wstr, opt->preci);
	else
		length = ft_wstrnconv(str, wstr, len);
	if (opt->preci_set && opt->preci < 0)
		add_nchar(out, ' ', ABS(length), opt);
	else
		add_str(out, str, length, opt);
}

void			flag_s(t_str *out, t_opt *opt, va_list *ap)
{
	char	*str;
	int		length;

	if (opt->preci_set && opt->preci < 0)
		opt->preci_set = 0;
	if (opt->format->name == 'S' || ft_strequ(opt->length, "l"))
	{
		flag_ws(out, opt, va_arg(*ap, wchar_t*));
		return ;
	}
	str = va_arg(*ap, char*);
	if (str == NULL && s_null(out, opt))
		return ;
	length = ft_strlen(str);
	if (opt->preci_set && length > opt->preci)
		length = opt->preci;
	if (opt->preci_set && opt->preci < 0)
		add_nchar(out, ' ', ABS(length), opt);
	else
		add_str(out, str, length, opt);
}
