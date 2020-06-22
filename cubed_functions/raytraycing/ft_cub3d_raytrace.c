/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cub3d_raytrace.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/11 11:40:45 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/22 16:47:54 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_direction_and_plane(t_ray *ray, int rot)
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

t_2doub		ft_set_start_position_player(t_2int pos_int)
{
	t_2doub	pos;

	pos.x = pos_int.x + 0.5;
	pos.y = pos_int.y + 0.5;
	return (pos);
}

void		ft_set_step_and_sidedistance(t_ray *ray, t_2int map)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (ray->pos.x - map.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (map.x + 1.0 - ray->pos.x) * ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (ray->pos.y - map.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (map.y + 1.0 - ray->pos.y) * ray->delta_dist.y;
	}
}

void	ft_set_line(t_ray *ray, int h)
{
	ray->line.length = (int)(h / ray->perp_wall_dist);
	ray->line.start = -ray->line.length / 2 + h / 2;
	if (ray->line.start < 0)
		ray->line.start = 0;
	ray->line.end = ray->line.length / 2 + h / 2;
	if (ray->line.end >= h)
		ray->line.end = h - 1;
}

void	ft_set_perpendicular_wall_distance(t_ray *ray, int coor_x)
{
	if (ray->side == 0)
	{
		ray->perp_wall_dist = (ray->pos_map.x - ray->pos.x +
										(1 - ray->step.x) / 2) / ray->ray_dir.x;
		ray->zbuffer[coor_x] = ray->perp_wall_dist;
	}
	else
	{
		ray->perp_wall_dist = (ray->pos_map.y - ray->pos.y +
										(1 - ray->step.y) / 2) / ray->ray_dir.y;
		ray->zbuffer[coor_x] = ray->perp_wall_dist;
	}
}

t_2doub		ft_set_start_deltadistance(t_2doub ray_dir)
{
	t_2doub	delta_dist;

	delta_dist.x = fabs(1 / ray_dir.x);
	delta_dist.y = fabs(1 / ray_dir.y);
	return (delta_dist);
}

t_2doub		ft_set_start_plane(double x, double y)
{
	t_2doub plane;

	plane.x = x;
	plane.y = y;
	return (plane);
}

void		ft_digital_differential_analysis(t_ray *ray)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->pos_map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->pos_map.y += ray->step.y;
			ray->side = 1;
		}
		if (ray->map[ray->pos_map.y][ray->pos_map.x] == 1)
			ray->hit = 1;
	}
}

t_2int	ft_get_pos_map(t_2doub pos)
{
	t_2int pos_map;

	pos_map.x = (int)pos.x;
	pos_map.y = (int)pos.y;
	return (pos_map);
}

void	ft_make_frame(t_info *info)
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
		info->ray.ray_dir.x = info->ray.dir.x + info->ray.plane.x * info->ray.camera_x;
		info->ray.ray_dir.y = info->ray.dir.y + info->ray.plane.y * info->ray.camera_x;
		info->ray.delta_dist = ft_set_start_deltadistance(info->ray.ray_dir);
		ft_set_step_and_sidedistance(&info->ray, info->ray.pos_map);
		ft_digital_differential_analysis(&info->ray);
		ft_set_perpendicular_wall_distance(&info->ray, coor_x);
		ft_set_line(&info->ray, info->parse.res.y);
		ft_put_texture(info, new_img, coor_x);
		coor_x++;
	}
	ft_draw_sprite(info, new_img);
	mlx_put_image_to_window(info->mlx.mlx, info->mlx.mlx_window, new_img->img, 0, 0);
}

void	ft_start(t_info *info)
{
	int		x;

	x = 0;
	info->ray.map = info->parse.map.map;
	info->ray.pos = ft_set_start_position_player(info->parse.map.posplayer.coor);
	ft_set_direction_and_plane(&info->ray, info->parse.map.posplayer.rot);
	info->ray.zbuffer = ft_calloc(info->parse.res.x, sizeof(double));
	ft_make_frame(info);
}

void	ft_cub3d_raytrace(t_info info)
{
	info.mlx.mlx_window = mlx_new_window(info.mlx.mlx, info.parse.res.x, info.parse.res.y, "Cub3d");
	info.img.one.img = mlx_new_image(info.mlx.mlx, info.parse.res.x, info.parse.res.y);
	info.img.one.addr = mlx_get_data_addr(info.img.one.img,
	&info.img.one.bits_per_pixel, &info.img.one.line_length, &info.img.one.endian);
	info.img.two.img = mlx_new_image(info.mlx.mlx, info.parse.res.x, info.parse.res.y);
	info.img.two.addr = mlx_get_data_addr(info.img.two.img,
	&info.img.two.bits_per_pixel, &info.img.two.line_length, &info.img.two.endian);
	ft_start(&info);
	mlx_hook(info.mlx.mlx_window, 2, 1L << 0, ft_key_press, &info);
	mlx_hook(info.mlx.mlx_window, 3, 1L << 1, ft_key_release, &info.move);
	mlx_hook(info.mlx.mlx_window, 17, 1L << 17, ft_close_screen, &info);
	mlx_loop_hook(info.mlx.mlx, ft_process_movement, &info);
	mlx_loop(info.mlx.mlx);
}
