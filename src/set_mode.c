/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:05:28 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/07 12:05:29 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		set_mode(t_mlx *ret, char *av_2)
{
	if (ft_strequ(av_2, "0"))
	{
		ret->mode = 0;
		return (1);
	}
	else if (ft_strequ(av_2, "1"))
	{
		ret->mode = 1;
		return (1);
	}
	else
		return (0);
}
