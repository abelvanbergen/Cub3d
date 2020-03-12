/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_floodfill_8neighbors.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 15:02:48 by avan-ber       #+#    #+#                */
/*   Updated: 2020/03/09 18:07:39 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include <string.h>

typedef	struct	s_coor
{
	int			x;
	int			y;
}				t_coor;

int	ft_floodfill_8neighbors(int **map, t_coor size, int x, int y)
{
	int	i;
	int	j;

	if (x < 0 || x >= size.x || y < 0 || y >= size.y || map[y][x] == ' ')
		return (-1);
	else if (map[y][x] == 1)
		return (0);
	else
	{
		map[y][x] = 1;
		i = -1;
		while (i <= 1)
		{
			j = -1;
			while (j <= 1)
			{
				if ((i || j) && ft_floodfill_8neighbors(map, size, x + i, y + j)
																		== -1)
					return (-1);
				j++;
			}
			i++;
		}
		return (1);
	}
}
