/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tools2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 13:42:11 by mporcher          #+#    #+#             */
/*   Updated: 2015/06/02 15:38:36 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strext(t_str *str, int need)
{
	char	*tmp;
	int		size;

	need = need + (str->length + 1);
	if (need < str->alloc_length)
		return (1);
	size = str->alloc_length - 1;
	while (need >= size)
		size = size + 24;
	tmp = (char *)malloc(sizeof(char) * size);
	if (tmp == NULL)
		return (0);
	str->alloc_length = size;
	if (str->content != NULL)
	{
		ft_memmove(tmp, str->content, sizeof(char) * str->length);
		ft_bzero(tmp + str->length, size - str->length);
		free(str->content);
	}
	else
		ft_bzero(tmp, size);
	str->content = tmp;
	return (1);
}

void	ft_str_ins(t_str *str, const char *ins, int index)
{
	ft_str_insl(str, ins, index, ft_strlen(ins));
}

void	ft_str_insl(t_str *str, const char *ins, int index, int l)
{
	if (!ft_strext(str, l))
		return ;
	ft_memmove(str->content + index + l, str->content + index,
		str->length - index);
	ft_memmove(str->content + index, ins, l);
	str->length += l;
}

void	ft_str_insc(t_str *str, char c, int index)
{
	ft_str_insl(str, &c, index, 1);
}

void	ft_stradd_de(t_str *str, double d, int preci)
{
	int		p;

	if (d < 0 && (d = -1) == -1)
		ft_stradd_c(str, '-');
	p = 0;
	while (d > 10)
	{
		d /= 10;
		p++;
	}
	while (d < 1)
	{
		d *= 10;
		p--;
	}
	ft_stradd_d(str, d, preci);
	ft_stradd(str, (p < 0) ? "e-" : "e+");
	if (p > -10 && p < 10)
		ft_stradd_c(str, '0');
	ft_stradd_i(str, (p < 0) ? -p : p);
}
