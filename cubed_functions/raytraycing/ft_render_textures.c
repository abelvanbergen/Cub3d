/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_render_textures.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 18:18:52 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/23 13:13:07 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			ft_get_wall_x(t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_x = ray->pos.y + ray->perp_wall_dist * ray->ray_dir.y;
	else
		ray->wall_x = ray->pos.x + ray->perp_wall_dist * ray->ray_dir.x;
	ray->wall_x -= floor(ray->wall_x);
}

static void			ft_get_tex_x(t_ray ray, t_imginfo texture, t_2int *tex)
{
	tex->x = (int)(ray.wall_x * (double)(texture.img_width));
	if (ray.side == 0 && ray.ray_dir.x > 0)
		tex->x = texture.img_width - tex->x - 1;
	if (ray.side == 1 && ray.ray_dir.y < 0)
		tex->x = texture.img_width - tex->x - 1;
}

static unsigned int	ft_set_color_ceiling_floor(t_info *info, int y)
{
	unsigned int	color;

	if (y < info->ray.line.start)
		color = info->parse.ceiling.mlx;
	else
		color = info->parse.floor.mlx;
	return (color);
}

static void			ft_set_tex_step_and_tex_pos(t_info *info, t_imginfo texture,
											double *tex_pos, double *tex_step)
{
	*tex_step = 1.0 * texture.img_height / info->ray.line.length;
	*tex_pos = (info->ray.line.start - info->parse.res.y / 2 +
									info->ray.line.length / 2) * (*tex_step);
}

void				ft_draw_texture(t_info *info, t_imginfo texture,
														t_imginfo *img, int x)
{
	double			tex_step;
	double			tex_pos;
	int				y;
	unsigned int	color;
	t_2int			tex;

	ft_get_wall_x(&info->ray);
	ft_get_tex_x(info->ray, texture, &tex);
	ft_set_tex_step_and_tex_pos(info, texture, &tex_pos, &tex_step);
	y = 0;
	while (y < info->parse.res.y)
	{
		if (y < info->ray.line.start || y > info->ray.line.end)
			color = ft_set_color_ceiling_floor(info, y);
		else
		{
			tex.y = (int)tex_pos & (texture.img_height - 1);
			tex_pos += tex_step;
			color = *(unsigned int*)(texture.addr + (tex.y *
				texture.line_length + tex.x * (texture.bits_per_pixel / 8)));
		}
		my_mlx_pixel_put(img, x, y, color);
		y++;
	}
}
