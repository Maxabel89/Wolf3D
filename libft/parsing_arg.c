/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 13:49:17 by mporcher          #+#    #+#             */
/*   Updated: 2015/06/02 15:15:24 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	get_arg(t_opt *opt, va_list *ap)
{
	if (ft_strequ(opt->length, "hh"))
		return ((long long int)(signed char)(va_arg(*ap, int)));
	if (ft_strequ(opt->length, "h"))
		return ((long long int)(short)(va_arg(*ap, int)));
	if (ft_strequ(opt->length, "ll"))
		return ((long long int)(va_arg(*ap, long long)));
	if (ft_strequ(opt->length, "l"))
		return ((long long int)(va_arg(*ap, long)));
	if (ft_strequ(opt->length, "j"))
		return ((long long int)(va_arg(*ap, intmax_t)));
	if (ft_strequ(opt->length, "t") || ft_strequ(opt->length, "I"))
		return ((long long int)(va_arg(*ap, ptrdiff_t)));
	if (ft_strequ(opt->length, "z"))
		return ((long long int)(va_arg(*ap, long)));
	return ((long long int)(va_arg(*ap, int)));
}

t_ulong			get_unsigned_arg(t_opt *opt, va_list *ap)
{
	if (ft_strequ(opt->length, "hh"))
		return ((t_ulong)(unsigned char)(va_arg(*ap, int)));
	if (ft_strequ(opt->length, "h"))
		return ((t_ulong)(unsigned short)(va_arg(*ap, int)));
	if (ft_strequ(opt->length, "ll"))
		return ((t_ulong)(va_arg(*ap, unsigned long long)));
	if (ft_strequ(opt->length, "l"))
		return ((t_ulong)(va_arg(*ap, unsigned long)));
	if (ft_strequ(opt->length, "j"))
		return ((t_ulong)(va_arg(*ap, uintmax_t)));
	if (ft_strequ(opt->length, "t"))
		return ((t_ulong)(va_arg(*ap, ptrdiff_t)));
	if (ft_strequ(opt->length, "z") || ft_strequ(opt->length, "I"))
		return ((t_ulong)(va_arg(*ap, size_t)));
	return ((t_ulong)(va_arg(*ap, unsigned int)));
}

long double		get_float_arg(t_opt *opt, va_list *ap)
{
	if (ft_strequ(opt->length, "L"))
		return (va_arg(*ap, long double));
	if (ft_strequ(opt->length, "l"))
		return ((long double)(va_arg(*ap, double)));
	return ((long double)(va_arg(*ap, double)));
}
