/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 15:08:04 by mporcher          #+#    #+#             */
/*   Updated: 2015/06/02 15:38:18 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_initstr(t_str *str)
{
	str->content = (char *)malloc(sizeof(char) * 16);
	if (str->content != NULL)
		ft_bzero(str->content, 16);
	str->length = 0;
	if (str->content == NULL)
		str->alloc_length = 0;
	else
		str->alloc_length = 16;
}

static int		parse_format2(t_str *out, t_opt *opt, const char *frmt, int n)
{
	if (frmt[n] != '\0')
	{
		add_str(out, frmt + n, 1, opt);
		n++;
	}
	free(opt->flags);
	return (n);
}

int				parse_format(t_str *out, const char *frmt, va_list *ap)
{
	int			i;
	t_opt		opt;
	t_format	*flag;

	flag = (t_format *)malloc(sizeof(t_format) * 16);
	if (flag == NULL)
		exit(2);
	flag_list(flag);
	flag_list2(flag);
	flag_list3(flag);
	i = -1;
	while (flag[++i].name != '\0')
	{
		if (flag[i].name == frmt[get_length(&opt, frmt)])
		{
			opt.format = flag + i;
			clear_dis(&opt);
			flag[i].func(out, &opt, ap);
			free(opt.flags);
			return (get_length(&opt, frmt) + 1);
		}
	}
	return (parse_format2(out, &opt, frmt, get_length(&opt, frmt)));
}

void			parsef(t_str *out, const char *format, va_list *ap)
{
	int		i;

	ft_strext(out, ft_strlen(format));
	i = 0;
	while (i >= 0)
	{
		if (format[i] == '%' || format[i] == '\0')
		{
			if (format[i] == '\0')
				break ;
			else if (format[i] == '%')
				i += parse_format(out, format + i + 1, ap);
		}
		else
			ft_stradd_c(out, format[i]);
		i++;
	}
}
