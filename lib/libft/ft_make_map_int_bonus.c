/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_map_int_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 11:34:03 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/26 18:24:24 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		**ft_make_map_int(int column, int row)
{
	int i;
	int	**result;

	i = 0;
	result = malloc(sizeof(int*) * column);
	if (result == 0)
		return (0);
	while (i < column)
	{
		result[i] = malloc(sizeof(int) * row);
		if (result[i] == 0)
		{
			ft_free_map_int(result, i);
			return (0);
		}
		i++;
	}
	return (result);
}
