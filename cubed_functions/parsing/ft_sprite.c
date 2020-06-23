/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sprite.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/22 13:10:18 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/23 10:26:56 by abelfrancis   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_pos_sprite(t_sprite *sprite, int **map, t_2int map_size)
{
	int i;
	int j;
	int k;

	sprite->pos = ft_calloc(sprite->count, sizeof(t_sprite_pos));
	if (!sprite)
		error_message1("ft_calloc for t_sprite_pos failed", 1);
	k = 0;
	j = 0;
	while (j < map_size.y)
	{
		i = 0;
		while (i < map_size.x)
		{
			if (map[j][i] == 2)
			{
				sprite->pos[k].coor.x = i + 0.5;
				sprite->pos[k].coor.y = j + 0.5;
				k++;
			}
			i++;
		}
		j++;
	}
}

void	ft_swap_sprite_info(t_sprite_pos *a, t_sprite_pos *b)
{
	t_sprite_pos c;

	c.coor.x = b->coor.x;
	c.coor.y = b->coor.y;
	c.distance = b->distance;
	b->coor.x = a->coor.x;
	b->coor.y = a->coor.y;
	b->distance = a->distance;
	a->coor.x = c.coor.x;
	a->coor.y = c.coor.y;
	a->distance = c.distance;
}

void	ft_sort_sprite_distance(t_sprite_pos *sprite_pos, int sprite_count)
{
	int		i;
	bool	change;

	if (sprite_count <= 1)
		return ;
	change = 1;
	while (change == 1)
	{
		change = 0;
		i = 1;
		while (i < sprite_count)
		{
			if (sprite_pos[i - 1].distance < sprite_pos[i].distance)
			{
				change = 1;
				ft_swap_sprite_info(&(sprite_pos[i - 1]), &(sprite_pos[i]));
			}
			i++;
		}
	}
}

void	ft_set_sprite_distance(t_sprite_pos *sprite_pos, int sprite_count,
																	t_2doub pos)
{
	int i;

	i = 0;
	while (i < sprite_count)
	{
		sprite_pos[i].distance = ((pos.x - sprite_pos[i].coor.x) *
			(pos.x - sprite_pos[i].coor.x)) + ((pos.y - sprite_pos[i].coor.y) *
												(pos.y - sprite_pos[i].coor.y));
		i++;
	}
}

void	ft_set_drawstart_and_drawend(t_s_utils *utils, t_info *info)
{
	utils->drawstart.y = -utils->sprite_height / 2 + info->parse.res.y / 2;
	if (utils->drawstart.y < 0)
		utils->drawstart.y = 0;
	utils->drawend.y = utils->sprite_height / 2 + info->parse.res.y / 2;
	if (utils->drawend.y >= info->parse.res.y)
		utils->drawend.y = info->parse.res.y - 1;
	utils->sprite_width = abs((int)(info->parse.res.y / utils->transform.y));
	utils->drawstart.x = -utils->sprite_width / 2 + utils->spritescreenx;
	if (utils->drawstart.x < 0)
		utils->drawstart.x = 0;
	utils->drawend.x = utils->sprite_width / 2 + utils->spritescreenx;
	if (utils->drawend.x >= info->parse.res.x)
		utils->drawend.x = info->parse.res.x - 1;
}

void	ft_set_invdet_transform_and_spritescreenx(t_s_utils *utils,
																t_info *info)
{
	utils->invdet = 1.0 /
	(info->ray.plane.x * info->ray.dir.y - info->ray.dir.x * info->ray.plane.y);
	utils->transform.x = utils->invdet *
		(info->ray.dir.y * utils->sprite.x - info->ray.dir.x * utils->sprite.y);
	utils->transform.y = utils->invdet * (-info->ray.plane.y
					* utils->sprite.x + info->ray.plane.x * utils->sprite.y);
	utils->spritescreenx = (int)((info->parse.res.x / 2) *
								(1 + utils->transform.x / utils->transform.y));
}

void	ft_set_sprite_vertical_line(t_s_utils *utils, t_info *info,
													t_imginfo *new_img, int j)
{
	int k;

	utils->tex.x = (int)(256 * (j - (-utils->sprite_width / 2 +
			utils->spritescreenx)) * info->parse.sprite.tex.img_width /
													utils->sprite_width) / 256;
	if (utils->transform.y > 0 && j > 0 && j < info->parse.res.x &&
									utils->transform.y < info->ray.zbuffer[j])
	{
		k = utils->drawstart.y;
		while (k < utils->drawend.y)
		{
			utils->d = k * 256 - info->parse.res.y * 128 +
													utils->sprite_height * 128;
			utils->tex.y = ((utils->d * info->parse.sprite.tex.img_height) /
													utils->sprite_height) / 256;
			utils->color = *(unsigned int*)(info->parse.sprite.tex.addr +
				(utils->tex.y * info->parse.sprite.tex.line_length +
				utils->tex.x * (info->parse.sprite.tex.bits_per_pixel / 8)));
			if ((utils->color & 0x00FFFFFF) != 0)
				my_mlx_pixel_put(new_img, j, k, utils->color);
			k++;
		}
	}
}

void	ft_draw_sprite(t_info *info, t_imginfo *new_img)
{
	t_s_utils	utils;
	int			i;
	int			j;
	int			k;

	ft_set_sprite_distance(info->parse.sprite.pos, info->parse.sprite.count,
																info->ray.pos);
	ft_sort_sprite_distance(info->parse.sprite.pos, info->parse.sprite.count);
	i = 0;
	while (i < info->parse.sprite.count)
	{
		utils.sprite.x = info->parse.sprite.pos[i].coor.x - info->ray.pos.x;
		utils.sprite.y = info->parse.sprite.pos[i].coor.y - info->ray.pos.y;
		ft_set_invdet_transform_and_spritescreenx(&utils, info);
		utils.sprite_height = abs((int)(info->parse.res.y / utils.transform.y));
		ft_set_drawstart_and_drawend(&utils, info);
		j = utils.drawstart.x;
		while (j < utils.drawend.x)
		{
			ft_set_sprite_vertical_line(&utils, info, new_img, j);
			j++;
		}
		i++;
	}
}