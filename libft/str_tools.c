/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 13:29:41 by mporcher          #+#    #+#             */
/*   Updated: 2015/06/02 15:15:17 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stradd_l(t_str *str, const char *add, int len)
{
	if (!ft_strext(str, len))
		return ;
	ft_memmove(str->content + str->length, add, len);
	str->length += len;
}

void	ft_stradd(t_str *str, const char *add)
{
	ft_stradd_l(str, add, ft_strlen(add));
}

void	ft_stradd_c(t_str *str, char c)
{
	if (!ft_strext(str, 1))
		return ;
	str->content[str->length] = c;
	str->length++;
}

void	ft_stradd_cn(t_str *str, char c, int n)
{
	char	*chars;
	int		i;

	chars = (char *)malloc(sizeof(char) * n);
	if (chars == NULL)
		return ;
	if (n < 0)
		return ;
	i = 0;
	while (i < n)
	{
		chars[i] = c;
		i++;
	}
	ft_stradd_l(str, chars, n);
}

void	add_str(t_str *out, const char *add, int len, t_opt *opt)
{
	char	*left;

	left = ft_strrchr(opt->flags, '-');
	if (left == NULL && opt->width > 0)
		ft_stradd_cn(out, ' ', opt->width - len);
	ft_stradd_l(out, add, len);
	if (left != NULL || opt->width < 0)
		ft_stradd_cn(out, ' ', ABS(opt->width) - len);
}
