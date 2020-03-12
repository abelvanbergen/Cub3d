/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_struct_info_zero.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 13:25:59 by avan-ber       #+#    #+#                */
/*   Updated: 2020/03/10 13:31:50 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_struct_colorelem_zero(t_colorelem *color)
{
	color->mlx = 0;
	color->set = 0;
}

static void	set_struct_res_zero(t_res *res)
{
	res->x = 0;
	res->y = 0;
	res->set = 0;
}

static void	set_struct_texelem_zero(t_texelem *tex)
{
	tex->img = 0;
	tex->img_height = 0;
	tex->img_width = 0;
	tex->set = 0;
}

static void	set_struct_map_zero(t_map *map)
{
	map->map = NULL;
	map->posplayer.coor.x = 0;
	map->posplayer.coor.y = 0;
	map->posplayer.rot = 0;
	map->posplayer.set = 0;
	map->size.x = 0;
	map->size.y = 0;
}

void	set_struct_info_zero(t_info *info)
{
	set_struct_res_zero(&info->res);
	set_struct_colorelem_zero(&info->floor);
	set_struct_colorelem_zero(&info->ceiling);
	set_struct_texelem_zero(&info->sprite_tex);
	set_struct_texelem_zero(&info->north_tex);
	set_struct_texelem_zero(&info->east_tex);
	set_struct_texelem_zero(&info->south_tex);
	set_struct_texelem_zero(&info->west_tex);
	set_struct_map_zero(&info->map);
	ft_bzero(info, sizeof(t_info));
}