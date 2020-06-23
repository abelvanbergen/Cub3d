/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_texture_jumptable.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 13:10:43 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/23 13:10:57 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
