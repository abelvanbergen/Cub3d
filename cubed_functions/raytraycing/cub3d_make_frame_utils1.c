/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_make_frame_utils1.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 14:01:44 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/23 17:02:27 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_2int	ft_get_pos_map(t_2doub pos)
{
	t_2int pos_map;

	pos_map.x = (int)pos.x;
	pos_map.y = (int)pos.y;
	return (pos_map);
}

void	ft_set_ray_dir(t_info *info)
{
	info->ray.ray_dir.x = info->ray.dir.x +
										info->ray.plane.x * info->ray.camera_x;
	info->ray.ray_dir.y = info->ray.dir.y +
										info->ray.plane.y * info->ray.camera_x;
}

t_2doub	ft_set_start_deltadistance(t_2doub ray_dir)
{
	t_2doub	delta_dist;

	delta_dist.x = fabs(1 / ray_dir.x);
	delta_dist.y = fabs(1 / ray_dir.y);
	return (delta_dist);
}

void	ft_set_step_and_sidedistance(t_ray *ray, t_2int map)
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

void	ft_digital_differential_analysis(t_ray *ray)
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
