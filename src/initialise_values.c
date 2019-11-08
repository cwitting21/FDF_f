/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:05:44 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/07 12:05:45 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		initialise_values(t_mlx *ret)
{
	ret->field = NULL;
	ret->max.x = 0;
	ret->max.y = 0;
	ret->max.z = 0;
	ret->min_color = 0x0000FF;
	ret->max.color = 0xFF0000;
	ret->img = NULL;
	ret->bpp = 0;
	ret->sl = 0;
	ret->endn = 0;
	ret->data = 0;
	ret->win = NULL;
	ret->mlx = NULL;
	ret->fd = -1;
	ret->mode = -1;
}
