/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:05:12 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/07 23:47:10 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void			set_coord(t_mlx *ret, int i, int j)
{
	ret->max.x = j;
	ret->max.y = i;
	ret->max.z = 0;
}

int					val_counter(char *line)
{
	int	j;
	int k;

	j = 0;
	k = 0;
	while (line[k])
	{
		while (line[k] && line[k] != ' ')
			k++;
		while (line[k] && line[k] == ' ')
			k++;
		j++;
	}
	return (j);
}

int					get_coords(char *str_av_1, t_mlx *ret, char *line)
{
	int	gnl_ret;
	int	vc;
	int	i;

	ret->fd = open(str_av_1, 0);
	
	if ((gnl_ret = get_next_line(ret->fd, &line)) <= 0)
		return ((int)display_error(ret, 3));
	
	vc = val_counter(line);
	i = 1;
	while ((gnl_ret = get_next_line(ret->fd, &line)) > 0)
	{
		if (vc != val_counter(line))
		{
			ft_strdel(&line);
			return ((int)display_error(ret, 5));
		}
		i++;
	}
	ft_strdel(&line);
	set_coord(ret, i, vc);
	close(ret->fd);
	return (1);
}
