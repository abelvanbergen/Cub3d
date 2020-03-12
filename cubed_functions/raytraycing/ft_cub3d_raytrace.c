/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cub3d_raytrace.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/11 11:40:45 by avan-ber       #+#    #+#                */
/*   Updated: 2020/03/12 18:05:05 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_2doub		ft_set_start_direction_player(int rot)
{
	t_2doub	dir;

	dir.x = 0;
	dir.y = 0;
	if (rot == north)
		dir.y = -1;
	else if (rot == east)
		dir.x = 1;
	else if (rot == south)
		dir.y = 1;
	else if (rot == west)
		dir.x = -1;
	return (dir);
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
		ray->side_dist.x = (map.x + 1.0 -  ray->pos.x) * ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (ray->pos.y - map.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (map.y + 1.0 -  ray->pos.y) * ray->delta_dist.y;
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

void	ft_set_perpendicular_wall_distance(t_ray *ray)
{
	if (ray->side == 0)
	{
		ray->perp_wall_dist = (ray->pos_map.x - ray->pos.x +
										(1 - ray->step.x) / 2) / ray->ray_dir.x;
	}
	else
	{
		ray->perp_wall_dist = (ray->pos_map.y - ray->pos.y +
										(1 - ray->step.y) / 2) / ray->ray_dir.y;
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

void	ft_put_line_to_window(t_data *img, t_ray ray, int x, int color)
{
	int i;

	i = ray.line.start;
	while (i < ray.line.end)
	{
		my_mlx_pixel_put(img, x, i, color);
		i++;
	}
}

void	ft_print_map_int(int **map, t_2int size)
{
	int i;
	int j;

	j = 0;
	while (j < size.y)
	{
		i = 0;
		while (i < size.x)
		{
			printf("%d ", map[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
}

t_2int	ft_get_pos_map(t_2doub pos)
{
	t_2int pos_map;

	pos_map.x = (int)pos.x;
	pos_map.y = (int)pos.y;
	return (pos_map);
}

void	ft_start(t_info info, t_data *img)
{
	t_ray	ray;
	int		x;

	x = 0;
	ray.map = info.map.map;
	ray.pos_map = info.map.posplayer.coor;
	ray.pos = ft_set_start_position_player(info.map.posplayer.coor);
	ray.dir = ft_set_start_direction_player(info.map.posplayer.rot);
	ray.plane = ft_set_start_plane(0.66, 0.);
	while (x < info.res.x)
	{
		ray.pos_map = ft_get_pos_map(ray.pos);
		ray.camera_x = 2 * x / (double)info.res.x - 1;
		ray.ray_dir.x = ray.dir.x + ray.plane.x * ray.camera_x;
		ray.ray_dir.y = ray.dir.y + ray.plane.y * ray.camera_x;
		ray.delta_dist = ft_set_start_deltadistance(ray.ray_dir);
		ft_set_step_and_sidedistance(&ray, ray.pos_map);
		ft_digital_differential_analysis(&ray);
		ft_set_perpendicular_wall_distance(&ray);
		ft_set_line(&ray, info.res.y);
		if (ray.side == 1)
			ft_put_line_to_window(img, ray, x, 0xFF0000);
		else
			ft_put_line_to_window(img, ray, x, 0xFF0000 / 3);
		x++;
	}
}

void	ft_cub3d_raytrace(t_info info)
{
	void	*mlx_window;
	t_data	img;
	t_2int	coor;
	int		color;

	mlx_window = mlx_new_window(info.mlx, info.res.x, info.res.y, "Cub3d");
	img.img = mlx_new_image(info.mlx, info.res.x, info.res.y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
																&img.endian);
	coor.y = 0;
	while (coor.y < info.res.y)
	{
		coor.x = 0;
		if (coor.y < info.res.y / 2)
			color = info.ceiling.mlx;
		else
			color = info.floor.mlx;
		while (coor.x < info.res.x)
		{
			my_mlx_pixel_put(&img, coor.x, coor.y, color);
			coor.x++;
		}
		coor.y++;
	}
	ft_start(info, &img);
	mlx_put_image_to_window(info.mlx, mlx_window, img.img, 0, 0);
	mlx_loop(info.mlx);
}