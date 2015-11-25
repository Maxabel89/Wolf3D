/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 19:58:14 by mporcher          #+#    #+#             */
/*   Updated: 2015/06/13 19:59:02 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf_3d.h"

void	ft_orientation_wall(t_env *e, float x, float y, int code)
{
	static int	key;

	if (code == 0)
		key = 0;
	if (e->map[(int)(round(x))][(int)(round(y))] == 1 && code == 0)
	{
		if (y < round(y))
			e->color_code = 1;
		else
			e->color_code = 2;
		key = 1;
	}
	if (e->map[(int)(round(x))][(int)(round(y))] == 1 && code == 1 && key == 0)
	{
		if (x < round(x))
			e->color_code = 3;
		else
			e->color_code = 4;
	}
}

int		ft_manage_color(t_env *e, float len)
{
	if (e->color_code == 1)
		return (ft_color(255, 165, 0, len));
	if (e->color_code == 2)
		return (ft_color(255, 20, 147, len));
	if (e->color_code == 3)
		return (ft_color(0, 255, 0, len));
	if (e->color_code == 4)
		return (ft_color(255, 255, 0, len));
	return (0);
}

void	ft_print_background(t_env *e)
{
	int		x;
	float	y;

	x = 0;
	while (x < WIDTH)
	{
		y = -1;
		while (y++ < HEIGHT / 2)
			mlx_put_px_img(e, x, y,
				ft_color(0, 255, 255, y / 25));
		x++;
	}
	x = -1;
	while (x++ < WIDTH)
	{
		y = HEIGHT / 2;
		while (y < HEIGHT)
		{
			mlx_put_px_img(e, x, y, ft_color(0, 0, 205, WIDTH * 9 / (2 * y)));
			y++;
		}
	}
}

int		ft_color(int r, int v, int b, float len)
{
	t_color	c;

	c.r = r - (r * len * COEF_DARK) / 256;
	c.v = v - (v * len * COEF_DARK) / 256;
	c.b = b - (b * len * COEF_DARK) / 256;
	return ((c.r * 256 * 256) + (c.v * 256) + c.b);
}
