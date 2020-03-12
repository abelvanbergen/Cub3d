/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intmapdup_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 16:36:24 by avan-ber       #+#    #+#                */
/*   Updated: 2020/03/10 16:36:53 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	**ft_intmapdup(int **map, t_2int size)
{
	int i;
	int j;
	int	**dup;

	dup = ft_make_map_int(size.x, size.y);
	if (dup == 0)
		return (0);
	j = 0;
	while (j < size.y)
	{
		i = 0;
		while (i < size.x)
		{
			dup[j][i] = map[j][i];
			i++;
		}
		j++;
	}
	return (dup);
}
