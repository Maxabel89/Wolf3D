/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_3d.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 16:15:11 by mporcher          #+#    #+#             */
/*   Updated: 2015/06/13 20:18:49 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WOLF_3D_H
# define FT_WOLF_3D_H

# include <math.h>
# include "../mlx_lib/mlx.h"
# include "../mlx_lib/X.h"
# include "../libft/libft.h"
# include "mlx.h"
# include <unistd.h>
# include <fcntl.h>

# define WIDTH 1600
# define HEIGHT 900
# define HEIGHT_WALL 40
# define FOV 60
# define MOVESPEED 0.15
# define RAY_ACCURACY 0.001
# define RAY_FAST 0.05
# define COEF_ROTATION 4
# define COEF_DARK 15

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			endian;
	int			bpp;
	int			size_line;
	float		x;
	float		y;
	float		j;
	float		k;
	float		angle;
	int			color_code;
	int			map[15][15];
	float		cpy_y;
	float		cpy_x;
	float		cpy_angle;
}				t_env;

typedef struct	s_color
{
	int			r;
	int			v;
	int			b;
}				t_color;

void			ft_print_background(t_env *e);
void			mlx_put_px_img(t_env *e, int x, int y, int color);
void			ft_map(int map[15][15]);
void			ft_map_42(int map[15][15]);
void			ft_corridor(int map[15][15]);
float			ft_ray_casting(int col, t_env *e);
void			scanning_screen(t_env *e);
void			ft_put_col_img(t_env *e, float len, int color, int col);
int				key_hook(int keycode, t_env *e);
int				expose_hook(t_env *e);
void			ft_key_down(t_env *e);
void			ft_key_up(t_env *es);
void			ft_orientation_wall(t_env *e, float x, float y, int code);
int				ft_manage_color(t_env *e, float len);
int				ft_color(int r, int v, int b, float len);
int				ft_opti_ray_casting(t_env **e, float a, float teta);

#endif
