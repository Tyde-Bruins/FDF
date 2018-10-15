/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 19:23:12 by revan-wy          #+#    #+#             */
/*   Updated: 2018/06/04 21:50:36 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hstck, const char *ndl, size_t n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (ndl[0] == '\0')
		return ((char*)hstck);
	while ((hstck[i] != '\0') && (i < (int)n))
	{
		while ((hstck[i + j] == ndl[j]) && (i + j < (int)n))
		{
			if (ndl[j + 1] == '\0')
				return ((char*)&hstck[i]);
			j++;
		}
		i++;
		j = 0;
	}
	return ((char*)NULL);
}
