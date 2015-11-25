/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 16:45:41 by mporcher          #+#    #+#             */
/*   Updated: 2015/06/02 15:15:22 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			flag_percent(t_str *out, t_opt *opt, va_list *ap)
{
	char			c;

	c = '%';
	add_str(out, &c, 1, opt);
	(void)ap;
}
