/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_resolution.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 08:59:01 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/30 16:20:21 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_check_res_layout(char **data)
{
	int	i;

	i = 0;
	while (ft_isdigit(data[1][i]) == 1)
		i++;
	if (data[1][i] != '\0')
		error_message1("There is a wrong character in Resolution->x", 1);
	i = 0;
	while (ft_isdigit(data[2][i]) == 1)
		i++;
	if (data[2][i] != '\0')
		error_message1("There is a wrong character in Resolution->y", 1);
}

void		get_resolution(char **data, t_res *resolution, void *mlx, bool save)
{
	t_2int	res;

	ft_check_res_layout(data);
	if (resolution->set == 1)
		error_message1("This element already exist\nElemnt: R", 1);
	if (ft_arraylen(data) != 3)
		error_message1("The element does not have the right amount of arguments\
		\nElement: R", 1);
	resolution->x = ft_atoi(data[1]);
	if (resolution->x <= 0)
		error_message1("Resolution->x is to small", 1);
	resolution->y = ft_atoi(data[2]);
	if (resolution->y <= 0)
		error_message1("Resolution->y is to small", 1);
	mlx_get_screen_size(mlx, &res.x, &res.y);
	if (save == 0)
	{
		if (resolution->x > res.x)
			resolution->x = res.x;
		if (resolution->y > res.y)
			resolution->y = res.y;
	}
	resolution->set = 1;
}
