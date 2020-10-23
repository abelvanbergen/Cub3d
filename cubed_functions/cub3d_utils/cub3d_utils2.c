/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_utils2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/26 17:44:12 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/26 17:48:35 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_destroy(t_info *info, char *message)
{
	if (info->mlx.mlx_window != 0)
		mlx_destroy_window(info->mlx.mlx, info->mlx.mlx_window);
	if (info->mlx.mlx_window != 0)
		mlx_destroy_image(info->mlx.mlx, info->img.one.img);
	if (info->mlx.mlx_window != 0)
		mlx_destroy_image(info->mlx.mlx, info->img.two.img);
	error_message1(message, 1);
}
