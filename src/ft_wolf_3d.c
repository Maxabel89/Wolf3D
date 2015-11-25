/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 16:18:08 by mporcher          #+#    #+#             */
/*   Updated: 2015/06/13 21:28:01 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf_3d.h"

int		expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

void	ft_choose_map(char **av, t_env *e)
{
	if (!ft_strcmp(av[1], "42"))
		ft_map_42(e->map);
	else if (!ft_strcmp("corridor", av[1]))
		ft_corridor(e->map);
	else
		ft_map(e->map);
}

int		main(int ac, char **av)
{
	t_env	e;

	e.x = 2;
	e.y = 7;
	if (ac == 2)
		ft_choose_map(av, &e);
	else
		ft_map(e.map);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "window");
	e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT);
	e.data = mlx_get_data_addr(e.img, &(e.bpp), &(e.size_line), &(e.endian));
	ft_print_background(&e);
	mlx_hook(e.win, 2, (1L << 0), key_hook, &e);
	e.angle = -M_PI / 2;
	scanning_screen(&e);
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
