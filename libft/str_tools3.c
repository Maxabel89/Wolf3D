/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tools3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 13:34:20 by mporcher          #+#    #+#             */
/*   Updated: 2015/06/02 15:38:43 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_str_rem(t_str *str, int index, int len)
{
	if (index >= str->length)
		return ;
	if ((index + len) > str->length)
		len = str->length - index;
	str->length -= len;
	ft_memmove(str->content + index, str->content + index + len,
		str->length - index);
	ft_bzero(str->content + str->length, len);
}

void			ft_strtrim_c(t_str *str, const char *trim)
{
	int				i;

	i = str->length - 1;
	while (i >= 0 && ft_strchr_idx(trim, str->content[i]) != -1)
		i--;
	i++;
	ft_str_rem(str, i, str->length - i);
	i = 0;
	while (ft_strchr_idx(trim, str->content[i]) != -1)
		i++;
	ft_str_rem(str, 0, i);
}

void			ft_stradd_upper(t_str *str, const char *add, int len)
{
	ft_strext(str, len);
	len += str->length;
	while (str->length < len)
	{
		if (*add >= 'a' && *add <= 'z')
			str->content[str->length++] = -32;
		else
			str->content[str->length++] = *add;
		add++;
	}
}

void			ft_stradd_lower(t_str *str, const char *add, int len)
{
	ft_strext(str, len);
	len += str->length;
	while (str->length < len)
	{
		if (*add >= 'a' && *add <= 'z')
			str->content[str->length++] = 32;
		else
			str->content[str->length++] = *add;
		add++;
	}
}

int				ft_atoin(const char *str, int len)
{
	int				nb;
	int				sign;

	sign = 1;
	nb = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
		len--;
	}
	else if (*str == '+')
	{
		len--;
		str++;
	}
	while (*str >= '0' && *str <= '9' && len-- > 0)
		nb = nb * 10 + (*(str++) - '0');
	return (nb * sign);
}
