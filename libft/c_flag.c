/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 17:11:27 by mporcher          #+#    #+#             */
/*   Updated: 2015/06/02 15:43:42 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		push_wide(char *buff, int i, wchar_t w)
{
	char			tmp[4];
	int				len;

	len = ft_wtoa(tmp, w);
	i -= len;
	ft_memcpy(buff + i + 1, tmp, len);
	return (i);
}

void	flag_c(t_str *out, t_opt *opt, va_list *ap)
{
	int		len;
	int		i;
	char	*c;

	len = MAX(opt->width, 1) * 4 + 1;
	c = (char *)ft_memalloc(len);
	if (c == NULL)
		exit (2);
	i = len - 1;
	if (opt->format->name == 'C' || ft_strequ(opt->length, "l"))
		i = push_wide(c, i, (wchar_t)va_arg(*ap, wint_t));
	else
	{
		c[i] = (char)va_arg(*ap, int);
		i--;
	}
	if (ft_strchr(opt->flags, '0')
		&& !ft_strchr(opt->flags, '-') && opt->width > 0)
		while ((len - i - 1) < opt->width)
		{
			c[i] = '0';
			i--;
		}
	add_str(out, c + 1 + i, len - 1 - i, opt);
}
