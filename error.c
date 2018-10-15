/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 11:32:53 by tbruins           #+#    #+#             */
/*   Updated: 2018/09/20 11:32:58 by tbruins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(int value)
{
	if (value == 0)
		ft_putendl("Error: Invalid File Type!");
	if (value == 1)
		ft_putendl("Error: Too few/many parameters!");
	if (value == 2)
		ft_putendl("Error: Map lines inconcistent!");
	exit(1);
}
