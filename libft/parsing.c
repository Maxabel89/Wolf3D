/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 14:27:41 by mporcher          #+#    #+#             */
/*   Updated: 2015/06/02 15:15:25 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		parse_flags(t_opt *opt, const char *format)
{
	int		i;

	i = 0;
	while (format[i] == '#' || format[i] == ' ' || format[i] == '0'
		|| format[i] == '-' || format[i] == '+' || format[i] == '\''
		|| is_separator(format[i]))
		i++;
	opt->flags = ft_strsub(format, 0, i);
	return (i);
}

static int		parse_width(t_opt *opt, const char *format)
{
	int		length;

	opt->width = 0;
	length = 0;
	while (ft_isdigit(format[length]))
		length++;
	if (length > 0)
		opt->width = ft_atoin(format, length);
	while (is_separator(format[length]))
		length++;
	return (length);
}

static int		parse_precision(t_opt *opt, const char *format)
{
	int		length;

	if (*format != '.')
	{
		opt->preci_set = 0;
		opt->preci = 0;
		return (0);
	}
	length = 1;
	while (format[length] == '.')
		length++;
	while (format[length] == '-')
		length++;
	opt->preci = ft_atoi(format + length - ((format[length - 1] == '-')
		? 1 : 0));
	while (ft_isdigit(format[length]))
		length++;
	while (is_separator(format[length]))
		length++;
	return (opt->preci_set = 1, length);
}

static int		parse_length(t_opt *opt, const char *format)
{
	int		i;
	int		len;
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * 10);
	if (tab == NULL)
		exit (2);
	format_len(tab);
	i = 0;
	while (tab[i] != NULL)
	{
		len = ft_strlen(tab[i]);
		if (ft_strnequ(tab[i], format, len))
		{
			opt->length = tab[i];
			while (is_separator(format[len]))
				len++;
			return (len);
		}
		i++;
	}
	opt->length = "";
	return (0);
}

int				get_length(t_opt *opt, const char *format)
{
	int		len;

	len = 0;
	len += parse_flags(opt, format + len);
	len += parse_width(opt, format + len);
	len += parse_precision(opt, format + len);
	len += parse_length(opt, format + len);
	return (len);
}
