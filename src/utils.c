/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:59:48 by tlynesse          #+#    #+#             */
/*   Updated: 2019/11/07 12:21:11 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_mlx		*free_mlx_ptr(t_mlx **mlx)
{
	int		i;

	if (mlx == NULL || *mlx == NULL)
		return (NULL);
	if ((*mlx)->mlx)
	{
		free((*mlx)->mlx);
		(*mlx)->mlx = 0;
	}
	if ((*mlx)->field != NULL)
	{
		i = -1;
		while (++i < (*mlx)->max.y)
			if ((*mlx)->field[i] != NULL)
			{
				free((*mlx)->field[i]);
				(*mlx)->field[i] = 0;
			}
	}
	if ((*mlx)->data)
	{
		free((*mlx)->data);
		(*mlx)->data = 0;
	}
	if ((*mlx)->img)
	{
		free((*mlx)->img);
		(*mlx)->img = 0;
	}
	if ((*mlx)->win)
	{
		free((*mlx)->win);
		(*mlx)->win = 0;
	}
	if (*mlx && (*mlx)->allocated)
	{
		free(*mlx);
		*mlx = NULL;
	}
	return (NULL);
}
