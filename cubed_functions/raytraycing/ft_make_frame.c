/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_frame.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 13:34:26 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/23 14:11:17 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_make_frame.h"
#include "cub3d.h"

void			ft_make_frame(t_info *info)
{
	int			coor_x;
	t_imginfo	*new_img;

	info->img.img_count++;
	if (info->img.img_count % 2 == 1)
		new_img = &info->img.one;
	else
		new_img = &info->img.two;
	coor_x = 0;
	while (coor_x < info->parse.res.x)
	{
		info->ray.pos_map = ft_get_pos_map(info->ray.pos);
		info->ray.camera_x = 2 * coor_x / (double)info->parse.res.x - 1;
		ft_set_ray_dir(info);
		info->ray.delta_dist = ft_set_start_deltadistance(info->ray.ray_dir);
		ft_set_step_and_sidedistance(&info->ray, info->ray.pos_map);
		ft_digital_differential_analysis(&info->ray);
		ft_set_perpendicular_wall_distance(&info->ray, coor_x);
		ft_set_line(&info->ray, info->parse.res.y);
		ft_put_texture(info, new_img, coor_x);
		coor_x++;
	}
	ft_draw_sprite(info, new_img);
	mlx_put_image_to_window(info->mlx.mlx, info->mlx.mlx_window,
															new_img->img, 0, 0);
}
