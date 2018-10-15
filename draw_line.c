/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 12:03:40 by tbruins           #+#    #+#             */
/*   Updated: 2018/09/12 12:24:02 by tbruins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_map *win, t_coord *coord)
{
	float	x;
	float	y;
	float	step;
	int		i;

	coord->dx = (coord->x2 - coord->x1);
	coord->dy = (coord->y2 - coord->y1);
	if (fabs(coord->dx) >= fabs(coord->dy))
		step = fabs(coord->dx);
	else
		step = fabs(coord->dy);
	coord->dx = coord->dx / step;
	coord->dy = coord->dy / step;
	x = coord->x1;
	y = coord->y1;
	i = 1;
	while (i <= step)
	{
		mlx_pixel_put(win->mlx, win->win, x, y, 0x00FFFFFF);
		x = x + coord->dx;
		y = y + coord->dy;
		i = i + 1;
	}
}

void	draw_row_line(t_map *map, int j, int i)
{
	t_coord		coord;

	coord.x1 = (j + i) * (10 / tan(30 * 0.0174533)) + 50;
	coord.y1 = (i - j) * 10 - 10 * map->int_map[i][j] + 450;
	coord.x2 = (j + i + 1) * (10 / tan(30 * 0.0174533)) + 50;
	coord.y2 = (i - j + 1) * 10 - 10 * map->int_map[i + 1][j] + 450;
	draw_line(map, &coord);
}

void	draw_col_line(t_map *map, int j, int i)
{
	t_coord		coord;

	coord.x1 = (j + i) * (10 / tan(30 * 0.0174533)) + 50;
	coord.y1 = (i - j) * 10 - 10 * map->int_map[i][j] + 450;
	coord.x2 = (j + i + 1) * (10 / tan(30 * 0.0174533)) + 50;
	coord.y2 = (i - j - 1) * 10 - 10 * map->int_map[i][j + 1] + 450;
	draw_line(map, &coord);
}
