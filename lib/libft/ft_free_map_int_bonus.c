/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_map_int_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 15:43:22 by avan-ber       #+#    #+#                */
/*   Updated: 2020/03/03 16:24:14 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free_map_int(int **array, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
