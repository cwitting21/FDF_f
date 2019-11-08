/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:04:40 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/07 12:11:34 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		ft_px_put(t_mlx *mlx, t_point *point, int color)
{
	if (point->x >= 0 && point->x < WIN_WIDTH &&
	point->y >= 0 && point->y < WIN_HIEGHT)
		mlx->data[point->x + point->y * WIN_WIDTH] = color;
}

static void		draw_line(t_mlx *mlx, void *win_ptr, t_line line)
{
	const int	signX = line.a->x < line.b->x ? 1 : -1;
	const int	signY = line.a->y < line.b->y ? 1 : -1;
	t_point		tmp;
	t_point		delta;
	int			error[2];

	tmp.x = line.a->x;
	tmp.y = line.a->y;
	delta.x = ft_abs(line.b->x - line.a->x);
	delta.y = ft_abs(line.b->y - line.a->y);
	error[0] = delta.x - delta.y;
	fill_color(mlx);
	while (tmp.x < line.b->x || tmp.y < line.b->y)
	{
		ft_px_put(mlx, &tmp, get_color(tmp, *(line.a), *(line.b), delta));
		if ((error[1] = error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			tmp.x += signX;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			tmp.y += signY;
		}
	}
}

void			draw(t_mlx *mlx, t_line line)
{
	int			i;
	int			j;

	i = -1;
	while (++i < mlx->max.y)
	{
		j = -1;
		while (++j < mlx->max.x)
		{
			if (j < mlx->max.x - 1)
			{
				line.a = &(mlx->field[i][j]);
				line.b = &(mlx->field[i][j + 1]);
				draw_line(mlx, mlx->win, line);
			}
			if (i < mlx->max.y - 1)
			{
				line.a = &(mlx->field[i][j]);
				line.b = &(mlx->field[i + 1][j]);
				draw_line(mlx, mlx->win, line);
			}
		}
	}
}
