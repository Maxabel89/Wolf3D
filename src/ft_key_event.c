/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 16:20:41 by mporcher          #+#    #+#             */
/*   Updated: 2015/06/13 21:27:50 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf_3d.h"

void	ft_key_up(t_env *e)
{
	e->y = e->y + MOVESPEED * cos(e->angle);
	if (e->map[(int)round(e->x)][(int)round(e->y)] != 0)
		e->y = e->y - MOVESPEED * cos(e->angle);
	e->x = e->x - MOVESPEED * sin(e->angle);
	if (e->map[(int)round(e->x)][(int)round(e->y)] != 0)
		e->x = e->x + MOVESPEED * sin(e->angle);
}

void	ft_key_down(t_env *e)
{
	e->y = e->y - MOVESPEED * cos(e->angle);
	if (e->map[(int)round(e->x)][(int)round(e->y)] != 0)
		e->y = e->y + MOVESPEED * cos(e->angle);
	e->x = e->x + MOVESPEED * sin(e->angle);
	if (e->map[(int)round(e->x)][(int)round(e->y)] != 0)
		e->x = e->x - MOVESPEED * sin(e->angle);
}

void	ft_position(int keycode, t_env *e)
{
	if (keycode == 15)
	{
		e->cpy_y = e->y;
		e->cpy_x = e->x;
		e->cpy_angle = e->angle;
	}
	if (keycode == 17)
	{
		e->y = e->cpy_y;
		e->x = e->cpy_x;
		e->angle = e->cpy_angle;
	}
	if (keycode == 11)
	{
		e->x = 2;
		e->y = 7;
		e->angle = -1.570796;
	}
}

int		key_hook(int keycode, t_env *e)
{
	ft_position(keycode, e);
	if (keycode == 53)
		exit(0);
	if (keycode == 11)
	{
		e->x = 2;
		e->y = 7;
		e->angle = -1.570796;
	}
	if (keycode == 126)
		ft_key_up(e);
	if (keycode == 125)
		ft_key_down(e);
	if (keycode == 123)
		e->angle = e->angle + ((COEF_ROTATION * M_PI) / 180);
	if (keycode == 124)
		e->angle = e->angle - ((COEF_ROTATION * M_PI) / 180);
	ft_print_background(e);
	scanning_screen(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}
