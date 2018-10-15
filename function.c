/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 14:32:07 by tbruins           #+#    #+#             */
/*   Updated: 2018/09/20 14:32:11 by tbruins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	function(t_map *win)
{
	t_in	in;

	in.i = -1;
	while (++in.i < win->row_cnt)
	{
		in.tmp = ft_strsplit(win->space[in.i], ' ');
		in.j = 0;
		while (in.j++ < win->col_cnt)
		{
			win->int_map[in.i][in.j - 1] = ft_atoi(in.tmp[in.j - 1]);
			free(in.tmp[in.j - 1]);
		}
		free(in.tmp);
	}
}
