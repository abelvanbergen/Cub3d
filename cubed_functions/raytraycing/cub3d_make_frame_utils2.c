/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_make_frame_utils2.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 14:05:27 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/23 14:10:57 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_set_perpendicular_wall_distance(t_ray *ray, int coor_x)
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

void		ft_set_line(t_ray *ray, int h)
{
	ray->line.length = (int)(h / ray->perp_wall_dist);
	ray->line.start = -ray->line.length / 2 + h / 2;
	if (ray->line.start < 0)
		ray->line.start = 0;
	ray->line.end = ray->line.length / 2 + h / 2;
	if (ray->line.end >= h)
		ray->line.end = h - 1;
}
