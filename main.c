/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 18:45:18 by tbruins           #+#    #+#             */
/*   Updated: 2018/09/13 14:19:38 by tbruins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mapmem(t_map *win, int fd)
{
	t_in in;

	in.i = 0;
	in.j = 0;
	win->space = (char **)malloc(sizeof(char *) * (win->row_cnt + 1));
	while (get_next_line(fd, &in.buf) > 0)
	{
		if (win->col_cnt)
			if (ft_getwcntsd(in.buf, ' ') != win->col_cnt)
				error(2);
		if (!win->col_cnt)
			win->col_cnt = ft_getwcntsd(in.buf, ' ');
		win->space[in.i] = ft_strdup(in.buf);
		free(in.buf);
		in.i++;
	}
	free(in.buf);
	in.tmp = ft_strsplit(win->space[0], ' ');
	while (in.tmp[in.j])
		free(in.tmp[in.j++]);
	free(in.tmp);
	in.j = 0;
	win->int_map = (int **)malloc(sizeof(int *) * win->row_cnt);
	while (in.j < win->row_cnt)
		win->int_map[in.j++] = (int *)malloc(sizeof(int) * win->col_cnt);
}

void	r_map(char *file, t_map *win, int fd)
{
	t_in	in;

	if (!(fd = open(file, O_RDONLY)) || fd == -1)
		error(0);
	while (get_next_line(fd, &in.buf) > 0)
	{
		win->row_cnt++;
		free(in.buf);
	}
	free(in.buf);
	close(fd);
	fd = open(file, O_RDONLY);
	mapmem(win, fd);
	function(win);
}

int		window(t_map *win)
{
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, 2560, 1440, "fdf");
	return (0);
}

void	draw_map(t_map *win)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < win->row_cnt)
	{
		j = 0;
		while (j < win->col_cnt)
		{
			if (j < win->col_cnt - 1)
				draw_col_line(win, j, i);
			if (i < win->row_cnt - 1)
				draw_row_line(win, j, i);
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	int		fd;
	t_map	*win;

	i = 0;
	j = 0;
	fd = 0;
	win = (t_map *)ft_memalloc(sizeof(t_map));
	if (argc == 2)
	{
		window(win);
		r_map(argv[1], win, fd);
		draw_map(win);
		mlx_key_hook(win->win, key_hook, 0);
		mlx_loop(win->mlx);
	}
	else
		error(1);
	return (0);
}
