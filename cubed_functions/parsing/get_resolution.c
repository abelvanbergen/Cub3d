/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_resolution.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 08:59:01 by avan-ber       #+#    #+#                */
/*   Updated: 2020/03/11 13:43:44 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_resolution(char **data, t_res *resolution, void *mlx)
{
	t_2int res;

	if (resolution->set == 1)
		error_message1("This element already exist\nElemnt: R", 1);
	if (ft_arraylen(data) != 3)
		error_message1("The element does not have the right amount of \
													 arguments\nElement: R", 1);
	resolution->x = ft_atoi(data[1]);
	if (resolution->x <= 0)
		error_message1("Resolution->x is to small", 1);
	resolution->y = ft_atoi(data[2]);
	if (resolution->y <= 0)
		error_message1("Resolution->x is to small", 1);
	mlx_get_screen_size(mlx, &res.x, &res.y);
	if(resolution->x > res.x)
		resolution->x = res.x;
	if(resolution->y > res.y)
		resolution->y = res.y;
	resolution->set = 1;
}
