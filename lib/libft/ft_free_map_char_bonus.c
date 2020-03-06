/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_map_char_bonus.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 12:08:46 by avan-ber       #+#    #+#                */
/*   Updated: 2020/03/06 12:13:00 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free_map_char(char **map, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
