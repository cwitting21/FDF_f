/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 22:17:41 by tlynesse          #+#    #+#             */
/*   Updated: 2019/11/08 00:58:40 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define WIN_WIDTH		1080
# define WIN_HIEGHT		1080

# define ARROW_LEFT		123
# define ARROW_RIGHT	124
# define ANGLE			0.523599

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_point;

typedef struct		s_line
{
	t_point			*a;
	t_point			*b;
}					t_line;

typedef struct		s_mlx
{
	void			*mlx;
	t_point			**field;
	int				mode;
	t_point			max;
	int				min_color;
	void			*img;
	void			*win;
	int				bpp;
	int				sl;
	int				endn;
	int				*data;
	double			scale;
	int				fd;
	int				allocated;
	// int				error;
}					t_mlx;

t_mlx				*read_file(int ac, char **av);

void				fill_color(t_mlx *mlx);

double				percent(int start, int end, int current);
int					get_light(int start, int end, double percentage);
int					get_color(t_point current, t_point start, t_point end,
					t_point delta);

int					ft_key_events(int key, t_mlx *mlx);
int					ft_mouse_events(int button, int x, int y, t_mlx *mlx);

t_mlx				*free_mlx_ptr(t_mlx **mlx);

int					get_coords(char *str_av_1, t_mlx *ret, char *line);
void				initialise_values(t_mlx *ret);
int					set_mode(t_mlx *ret, char *av_2);
void				iso_lines(t_line line);
void				draw(t_mlx *mlx, t_line line);

void				clean(t_mlx *mlx);
t_mlx				*display_error(t_mlx *mlx, int mode);

#endif
