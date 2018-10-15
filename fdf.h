/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 09:10:39 by tbruins           #+#    #+#             */
/*   Updated: 2018/09/19 12:23:25 by tbruins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

typedef struct	s_map
{
	void		*mlx;
	void		*win;
	int			**int_map;
	int			row_cnt;
	int			col_cnt;
	char		**space;
}				t_map;

typedef struct	s_coord
{
	float		x1;
	float		y1;
	float		x2;
	float		y2;
	float		dx;
	float		dy;
	int			i;
}				t_coord;

typedef struct	s_in
{
	int			i;
	int			j;
	char		*buf;
	char		**tmp;
}				t_in;

void			r_map(char *file, t_map *win, int fd);
void			error(int value);
void			mapmem(t_map *win, int fd);
void			draw_map(t_map *win);
void			draw_row_line(t_map *map, int i, int j);
void			draw_col_line(t_map *map, int i, int j);
int				window(t_map *win);
int				key_hook(int e);
void			draw_line(t_map *win, t_coord *coord);
void			function(t_map	*win);

#endif
