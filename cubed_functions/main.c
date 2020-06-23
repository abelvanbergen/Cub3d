/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 16:50:31 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/23 16:50:40 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_info	info;

	ft_bzero(&info, sizeof(t_info));
	info.mlx.mlx = mlx_init();
	ft_parsefile(&info, av[1]);
	ft_cub3d_raytrace(info);
	return (0);
}
