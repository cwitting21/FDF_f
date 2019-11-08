/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:18:33 by tlynesse          #+#    #+#             */
/*   Updated: 2019/11/08 00:00:26 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		get_scale(t_mlx *mlx)
{
	double		ji;
	double		wh;


	ji = (double)mlx->max.x / (double)mlx->max.y;
	wh = (double)WIN_WIDTH / (double)WIN_HIEGHT;
	if (wh < ji)
		mlx->scale = ((2 * WIN_WIDTH) / (3 * (mlx->max.x)));
	else if (wh > ji)
		mlx->scale = ((2 * WIN_HIEGHT) / (3 * (mlx->max.y)));
	else
		mlx->scale = ((WIN_HIEGHT) / (5 * (mlx->max.y)));

}

void			change_mode(t_mlx *ret, int i, int j)
{
	int	prev_x;
	int	prev_y;

	if (ret->mode == 1)
	{
		prev_x = ret->field[i][j].x * ret->scale;
		prev_y = ret->field[i][j].y * ret->scale;
		ret->field[i][j].x = ((prev_x - prev_y) * cos(0.523599)) + WIN_WIDTH / 2;
		ret->field[i][j].y = ((prev_x + prev_y) * sin(0.523599) - ret->field[i][j].z) + WIN_HIEGHT / 2;
	}
	else
	{
		ret->field[i][j].x = ret->field[i][j].x * ret->scale + WIN_WIDTH / 2;
		ret->field[i][j].y = ret->field[i][j].y * ret->scale + WIN_HIEGHT / 2;
	}
}

void			fill_xyz(char *line, t_mlx *ret, int i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (line[k])
	{
		ret->field[i][j].x = (j - ret->max.x / 2);
		ret->field[i][j].y = (i - ret->max.y / 2);
		ret->field[i][j].z = ret->scale * ft_atoi(&line[k]);
		if (ret->field[i][j].z > ret->max.z)
			ret->max.z = ret->field[i][j].z;
		change_mode(ret, i, j);
		while (line[k] && line[k] != ' ')
			k++;
		while (line[k] && line[k] == ' ')
			k++;
		j++;
	}
}

static int		ft_start_init(t_mlx **ret, char **file, char **mode, int *gnl_ret)
{
	char	*line;

	
	if (((*ret = (t_mlx*)malloc(sizeof(t_mlx))) == NULL) ||
	(((*ret)->mlx = (void*)malloc(sizeof(void))) == NULL))
		return (2);
	initialise_values(*ret);
	if (set_mode(*ret, *mode) == 0)
		return (4);
	if ((*gnl_ret = (get_coords(*file, *ret, line))) < 0)
		return (3);
	else if (*gnl_ret == 0)
		return (0);
	get_scale(*ret);
	return (-1);
}

t_mlx			*read_file(int ac, char **av)
{
	t_mlx		*ret;
	char		*line;
	int			i;
	int			gnl_ret;
	int			tmp;

	tmp = ft_start_init(&ret, &av[1], &av[2], &gnl_ret);
	if (tmp == 2 || tmp == 3 || tmp == 4)
		return(display_error(ret, tmp));
	else if (tmp == 0)
		return (NULL);
	if ((ret->field = (t_point**)malloc(sizeof(t_point*) * ret->max.y)) == NULL)
		return (free_mlx_ptr(&ret));
	i = -1;
	while (++i < ret->max.y)
		if ((ret->field[i] = (t_point*)malloc(sizeof(t_point) * ret->max.x)) == NULL)
			return (free_mlx_ptr(&ret));
	i = 0;
	ret->fd = open(av[1], 0);
	while ((gnl_ret = get_next_line(ret->fd, &line)) > 0)
		fill_xyz(line, ret, i++);
	if (gnl_ret == -1)
		return (display_error(ret, 3));
	close(ret->fd);
	return (ret);
}
