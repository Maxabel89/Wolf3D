/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 14:11:09 by mporcher          #+#    #+#             */
/*   Updated: 2015/06/02 15:38:25 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pad_preci(t_str *str, int start, t_opt *opt)
{
	if (ft_strchr(opt->flags, '0') && !ft_strchr(opt->flags, '-'))
		while (str->length < opt->width)
			ft_str_insc(str, '0', start);
	while (str->length < opt->preci + start)
		ft_str_insc(str, '0', start);
	while (str->length < -opt->preci)
		ft_stradd_c(str, ' ');
}

int		is_separator(char c)
{
	if (c == ',' || c == ';' || c == ':' || c == '_')
		return (1);
	else
		return (0);
}

void	clear_dis(t_opt *opt)
{
	int		i;

	i = 0;
	while (opt->flags[i] != '\0')
	{
		if (ft_strchr(opt->format->disabled, opt->flags[i]))
			opt->flags[i] = ';';
		i++;
	}
}

int		ft_printf(const char *format, ...)
{
	t_str		display;
	va_list		ap;

	ft_initstr(&display);
	va_start(ap, format);
	parsef(&display, (char *)format, &ap);
	ft_strput(&display);
	va_end(ap);
	free(display.content);
	return (display.length);
}
