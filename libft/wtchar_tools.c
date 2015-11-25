/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtchar_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 16:07:14 by mporcher          #+#    #+#             */
/*   Updated: 2015/06/02 15:38:52 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_wstrlen(wchar_t *wstr)
{
	unsigned int	i;

	if (wstr == NULL)
		return (0);
	i = 0;
	while (wstr[i] != '\0')
		i++;
	return (i);
}

int				ft_wstrconv(char *buff, wchar_t *wstr)
{
	int				i;
	int				size;

	size = 0;
	i = -1;
	while (wstr[++i] != 0)
		size = size + ft_wtoa(buff + size, wstr[i]);
	return (size);
}

int				ft_wstrnconv(char *buff, wchar_t *wstr, int n)
{
	int				i;
	int				tmp;
	int				len;

	len = 0;
	i = 0;
	while (wstr[i] != 0)
	{
		tmp = ft_wtoa(buff + len, wstr[i]);
		if ((tmp + len) > n)
			break ;
		len = len + tmp;
		i++;
	}
	return (len);
}

int				ft_wtoa(char *buff, wchar_t w)
{
	if (w < 0x80)
		return (*buff = ((w & 0x7F) | 0), 1);
	else if (w < 0x800)
	{
		*(buff++) = ((w >> 6) & 0x1F) | 0xC0;
		*(buff++) = ((w >> 0) & 0x3F) | 0x80;
		return (2);
	}
	else if (w < 0x10000)
	{
		*(buff++) = ((w >> 12) & 0xF) | 0xE0;
		*(buff++) = ((w >> 6) & 0x3F) | 0x80;
		*(buff++) = ((w >> 0) & 0x3F) | 0x80;
		return (3);
	}
	else if (w < 0x110000)
	{
		*(buff++) = ((w >> 18) & 0x7) | 0xF0;
		*(buff++) = ((w >> 12) & 0x3F) | 0x80;
		*(buff++) = ((w >> 6) & 0x3F) | 0x80;
		*(buff++) = ((w >> 0) & 0x3F) | 0x80;
		return (4);
	}
	return (0);
}
