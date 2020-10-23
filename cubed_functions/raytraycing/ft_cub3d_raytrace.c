/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cub3d_raytrace.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/11 11:40:45 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/26 17:49:18 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_2doub	ft_set_start_position_player(t_2int pos_int)
{
	t_2doub	pos;

	pos.x = pos_int.x + 0.5;
	pos.y = pos_int.y + 0.5;
	return (pos);
}

static void		ft_set_direction_and_plane(t_ray *ray, int rot)
{
	if (rot == north)
	{
		ray->dir.y = -1;
		ray->plane.x = 0.66;
	}
	else if (rot == east)
	{
		ray->dir.x = 1;
		ray->plane.y = 0.66;
	}
	else if (rot == south)
	{
		ray->dir.y = 1;
		ray->plane.x = -0.66;
	}
	else if (rot == west)
	{
		ray->dir.x = -1;
		ray->plane.y = -0.66;
	}
}

void			ft_start(t_info *info)
{
	int		x;

	x = 0;
	info->ray.map = info->parse.map.map;
	info->ray.pos =
				ft_set_start_position_player(info->parse.map.posplayer.coor);
	ft_set_direction_and_plane(&info->ray, info->parse.map.posplayer.rot);
	info->ray.zbuffer = ft_calloc(info->parse.res.x, sizeof(double));
	if (!info->ray.zbuffer)
		error_message1("ft_calloc failed for zbuffer", 1);
	ft_make_frame(info);
}

static void		ft_get_images(t_info *info)
{
	info->img.one.img = mlx_new_image(info->mlx.mlx,
										info->parse.res.x, info->parse.res.y);
	if (info->img.one.img == 0)
		error_destroy(info, "mlx_new_image failed");
	info->img.one.addr = mlx_get_data_addr(info->img.one.img,
				&info->img.one.bits_per_pixel, &info->img.one.line_length,
														&info->img.one.endian);
	if (info->img.one.addr == 0)
		error_destroy(info, "mlx_get_data_addr failed");
	info->img.two.img = mlx_new_image(info->mlx.mlx, info->parse.res.x,
															info->parse.res.y);
	if (info->img.two.img == 0)
		error_destroy(info, "mlx_new_image failed");
	info->img.two.addr = mlx_get_data_addr(info->img.two.img,
			&info->img.two.bits_per_pixel, &info->img.two.line_length,
														&info->img.two.endian);
	if (info->img.two.img == 0)
		error_destroy(info, "mlx_get_data_addr failed");
}

void			ft_cub3d_raytrace(t_info info)
{
	info.mlx.mlx_window = mlx_new_window(info.mlx.mlx, info.parse.res.x,
													info.parse.res.y, "Cub3d");
	if (info.mlx.mlx_window == 0)
		error_message1("mlx_new_window failed", 1);
	ft_get_images(&info);
	ft_start(&info);
	mlx_hook(info.mlx.mlx_window, 2, 1L << 0, ft_key_press, &info);
	mlx_hook(info.mlx.mlx_window, 3, 1L << 1, ft_key_release, &info.move);
	mlx_hook(info.mlx.mlx_window, 17, 1L << 17, ft_close_screen, &info);
	mlx_loop_hook(info.mlx.mlx, ft_process_movement, &info);
	mlx_loop(info.mlx.mlx);
}
