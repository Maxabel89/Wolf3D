/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 16:21:56 by mporcher          #+#    #+#             */
/*   Updated: 2015/06/13 21:40:14 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf_3d.h"
#include <fcntl.h>

void	ft_put_col_img(t_env *e, float len, int color, int col)
{
	int		height_wall;
	int		i;

	i = 0;
	if (len > 0.5)
		height_wall = HEIGHT / (2 * len);
	else
		height_wall = HEIGHT / 2 + 1;
	col += WIDTH / 2;
	while (i < height_wall)
	{
		mlx_put_px_img(e, col, HEIGHT / 2 + i, color);
		mlx_put_px_img(e, col, HEIGHT / 2 - i, color);
		i++;
	}
}

void	mlx_put_px_img(t_env *e, int x, int y, int color)
{
	if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
		ft_memcpy(&(e->data[y * WIDTH * 4 + x * 4]), &color, 4);
}

void	ft_corridor(int map[15][15])
{
	int		j;
	int		i;
	int		index;
	char	*line;

	i = open("./maps/corridor", O_RDONLY);
	if (get_next_line(i, &line) == -1)
		ft_putexit("Error: can't read the map", 2);
	i = close(i);
	i = 0;
	index = 0;
	while (i < 15)
	{
		j = 0;
		while (j < 15)
		{
			map[i][j] = (line[index] == '1') ? 1 : 0;
			index++;
			j++;
		}
		i++;
	}
}

void	ft_map_42(int map[15][15])
{
	int		j;
	int		i;
	int		index;
	char	*line;

	i = open("./maps/43", O_RDONLY);
	if (get_next_line(i, &line) == -1)
		ft_putexit("Error: can't read the map", 2);
	i = close(i);
	i = 0;
	index = 0;
	while (i < 15)
	{
		j = 0;
		while (j < 15)
		{
			map[i][j] = (line[index] == '1') ? 1 : 0;
			index++;
			j++;
		}
		i++;
	}
}

void	ft_map(int map[15][15])
{
	int		j;
	int		i;
	int		index;
	char	*line;

	i = open("./maps/42", O_RDONLY);
	if (get_next_line(i, &line) == -1)
		ft_putexit("Error: can't read the map", 2);
	i = close(i);
	i = 0;
	index = 0;
	while (i < 15)
	{
		j = 0;
		while (j < 15)
		{
			map[i][j] = (line[index] == '1') ? 1 : 0;
			index++;
			j++;
		}
		i++;
	}
}
