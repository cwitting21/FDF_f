/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 03:21:25 by tlynesse          #+#    #+#             */
/*   Updated: 2019/11/08 00:58:21 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int					main(int ac, char **av)
{
	t_mlx			*mlx;
	t_line			line;

	// mlx->error = 0;
	mlx = NULL;
	if (ac != 3 || !(mlx = read_file(ac, av)))
		return ((int)display_error(mlx, 1));
	// if (mlx->error == -1)
	// 	return (0);
	if ((mlx->mlx = mlx_init()) == 0)
		return ((int)free_mlx_ptr(&mlx));
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HIEGHT, "My Window");
	mlx->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HIEGHT);
	mlx->data = (int *)mlx_get_data_addr(mlx->img, &(mlx->bpp), &(mlx->sl), &(mlx->endn));
	draw(mlx, line);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_hook(mlx->win, 2, 0, ft_key_events, mlx->mlx);
	mlx_loop(mlx->mlx);
	// display_error(mlx, win_ptr, -1, 0);
	// full_clean(&mlx, win_ptr, );
	// if ((mlx)->data)
	// 	free((mlx)->data);
	// if ((mlx)->img)
	// 	free((mlx)->img);
	//if (mlx->mlx && mlx->win)
	//	mlx_destroy_window(mlx->mlx, mlx->win);
	return (0);
}
