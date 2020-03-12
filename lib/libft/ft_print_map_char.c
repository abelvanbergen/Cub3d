/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_map_char.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 16:42:28 by avan-ber       #+#    #+#                */
/*   Updated: 2020/03/11 12:03:09 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_map_char(char **data)
{
	int i;

	i = 0;
	while (data[i])
	{
		ft_putendl_fd(data[i], 1);
		i++;
	}
}
