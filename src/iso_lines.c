/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:05:19 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/07 12:15:32 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		iso_lines(t_line line)
{
	int		prev_x1;
	int		prev_x2;
	int		prev_y1;
	int		prev_y2;

	prev_x1 = line.a->x;
	prev_x2 = line.b->x;
	prev_y1 = line.a->y;
	prev_y2 = line.b->y;
	line.a->x = (prev_x1 - prev_y1) * cos(ANGLE) + 444;
	line.a->y = -line.a->z + (prev_x1 + prev_y1) * sin(ANGLE) - line.a->z / 10;
	line.b->x = (prev_x2 - prev_y2) * cos(ANGLE) + 444;
	line.b->y = -line.b->z + (prev_x2 + prev_y2) * sin(ANGLE) - line.b->z / 10;
}
