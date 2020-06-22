/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_render_textures.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 18:18:52 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/22 12:59:05 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_wall_x(t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_x = ray->pos.y + ray->perp_wall_dist * ray->ray_dir.y;
	else
		ray->wall_x = ray->pos.x + ray->perp_wall_dist * ray->ray_dir.x;
	ray->wall_x -= floor(ray->wall_x);
}

void	ft_get_tex_x(t_ray ray, t_imginfo texture, t_2int *tex)
{
	tex->x = (int)(ray.wall_x * (double)(texture.img_width));
	if (ray.side == 0 && ray.ray_dir.x > 0)
		tex->x = texture.img_width - tex->x - 1;
	if (ray.side == 1 && ray.ray_dir.y < 0)
		tex->x = texture.img_width - tex->x - 1;
}

void	ft_draw_texture(t_info *info, t_imginfo texture, t_imginfo *img, int x)
{
	double			tex_step;
	double			tex_pos;
	int				y;
	unsigned int	color;
	t_2int			tex;

	ft_get_wall_x(&info->ray);
	ft_get_tex_x(info->ray, texture, &tex);
	tex_step = 1.0 * texture.img_height / info->ray.line.length;
	tex_pos = (info->ray.line.start - info->parse.res.y / 2 + info->ray.line.length / 2) * tex_step;
	y = 0;
	while (y < info->parse.res.y)
	{
		if (y < info->ray.line.start)
			color = info->parse.ceiling.mlx;
		else if (y > info->ray.line.end)
			color = info->parse.floor.mlx;
		else
		{
			tex.y = (int)tex_pos & (texture.img_height - 1);
			tex_pos += tex_step;
			color = *(unsigned int*)(texture.addr + (tex.y * texture.line_length + tex.x * (texture.bits_per_pixel / 8)));
		}
		my_mlx_pixel_put(img, x, y, color);
		y++;
	}
}

void	ft_put_texture(t_info *info, t_imginfo *img, int x)
{
	if (info->ray.side == 0 && info->ray.ray_dir.x >= 0)
		ft_draw_texture(info, info->parse.east_tex, img, x);
	else if (info->ray.side == 0 && info->ray.ray_dir.x < 0)
		ft_draw_texture(info, info->parse.west_tex, img, x);
	else if (info->ray.side == 1 && info->ray.ray_dir.y >= 0)
		ft_draw_texture(info, info->parse.south_tex, img, x);
	else
		ft_draw_texture(info, info->parse.north_tex, img, x);
}
