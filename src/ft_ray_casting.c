/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 16:19:41 by mporcher          #+#    #+#             */
/*   Updated: 2015/06/13 16:20:21 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf_3d.h"

void	scanning_screen(t_env *e)
{
	int		col;
	float	len;

	col = -WIDTH / 2;
	while (col < (WIDTH / 2 + WIDTH % 2))
	{
		len = ft_ray_casting(col, e);
		ft_put_col_img(e, len, ft_manage_color(e, len), col);
		col++;
	}
}

float	ft_ray_casting(int col, t_env *e)
{
	float		len;
	float		teta;

	teta = FOV * M_PI * (-col) / (WIDTH * 180);
	e->j = e->x;
	e->k = e->y;
	ft_opti_ray_casting(&e, RAY_FAST, teta);
	while (e->map[(int)(round(e->j))][(int)(round(e->k))] == 0)
	{
		e->k = e->k + RAY_ACCURACY * cos(e->angle + teta);
		ft_orientation_wall(e, e->j, e->k, 0);
		e->j = e->j - RAY_ACCURACY * sin(e->angle + teta);
		ft_orientation_wall(e, e->j, e->k, 1);
	}
	len = sqrt(pow(e->k - e->y, 2) + pow(e->j - e->x, 2));
	return (len * cos(teta));
}

int		ft_opti_ray_casting(t_env **e, float a, float teta)
{
	if (a < RAY_ACCURACY)
		return (0);
	while ((*e)->map[(int)(round((*e)->j))][(int)(round((*e)->k))] == 0)
	{
		(*e)->k = (*e)->k + a * cos((*e)->angle + teta);
		(*e)->j = (*e)->j - a * sin((*e)->angle + teta);
	}
	(*e)->k = (*e)->k - a * cos((*e)->angle + teta);
	(*e)->j = (*e)->j + a * sin((*e)->angle + teta);
	return (ft_opti_ray_casting(e, a / 2, teta));
}
