/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_move.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 11:09:11 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/22 17:12:05 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rotate(double rot, t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->ray.dir.x;
	info->ray.dir.x = (info->ray.dir.x * cos(rot)) - (info->ray.dir.y * sin(rot));
	info->ray.dir.y = (old_dir_x * sin(rot)) + (info->ray.dir.y * cos(rot));
	old_plane_x = info->ray.plane.x;
	info->ray.plane.x = (info->ray.plane.x * cos(rot)) - (info->ray.plane.y * sin(rot));
	info->ray.plane.y = (old_plane_x * sin(rot)) + (info->ray.plane.y * cos(rot));
}

void	ft_move_left(t_info *info)
{
	double	old_pos_x;
	t_2int	pot_pos;

	old_pos_x = info->ray.pos.x;
	pot_pos.x = info->ray.pos.x + (info->ray.dir.y * 0.2);
	pot_pos.y = info->ray.pos.y;
	if (info->ray.map[pot_pos.y][pot_pos.x] != 1 && info->ray.map[pot_pos.y][pot_pos.x] != 2)
		info->ray.pos.x += (info->ray.dir.y * 0.1);
	pot_pos.x = old_pos_x;
	pot_pos.y = info->ray.pos.y - (info->ray.dir.x * 0.2);
	if (info->ray.map[pot_pos.y][pot_pos.x] != 1 && info->ray.map[pot_pos.y][pot_pos.x] != 2)
		info->ray.pos.y -= (info->ray.dir.x * 0.1);
}

void	ft_move_right(t_info *info)
{
	double	old_pos_x;
	t_2int	pot_pos;

	old_pos_x = info->ray.pos.x;
	pot_pos.x = info->ray.pos.x - (info->ray.dir.y * 0.2);
	pot_pos.y = info->ray.pos.y;
	if (info->ray.map[pot_pos.y][pot_pos.x] != 1 && info->ray.map[pot_pos.y][pot_pos.x] != 2)
		info->ray.pos.x -= (info->ray.dir.y * 0.1);
	pot_pos.x = old_pos_x;
	pot_pos.y = info->ray.pos.y + (info->ray.dir.x * 0.2);
	if (info->ray.map[pot_pos.y][pot_pos.x] != 1 && info->ray.map[pot_pos.y][pot_pos.x] != 2)
		info->ray.pos.y += (info->ray.dir.x * 0.1);
}

void	ft_move_forward(t_info *info)
{
	double	old_pos_x;
	t_2int	pot_pos;

	old_pos_x = info->ray.pos.x;
	pot_pos.x = info->ray.pos.x + info->ray.dir.x * 0.2;
	pot_pos.y = info->ray.pos.y;
	if (info->ray.map[pot_pos.y][pot_pos.x] != 1 && info->ray.map[pot_pos.y][pot_pos.x] != 2)
		info->ray.pos.x += (info->ray.dir.x * 0.1);
	pot_pos.x = old_pos_x;
	pot_pos.y = info->ray.pos.y + info->ray.dir.y * 0.2;
	if (info->ray.map[pot_pos.y][pot_pos.x] != 1 && info->ray.map[pot_pos.y][pot_pos.x] != 2)
		info->ray.pos.y += (info->ray.dir.y * 0.1);
}

void	ft_move_backward(t_info *info)
{
	double	old_pos_x;
	t_2int	pot_pos;

	old_pos_x = info->ray.pos.x;
	pot_pos.x = info->ray.pos.x - info->ray.dir.x * 0.2;
	pot_pos.y = info->ray.pos.y;
	if (info->ray.map[pot_pos.y][pot_pos.x] != 1 && info->ray.map[pot_pos.y][pot_pos.x] != 2)
		info->ray.pos.x -= (info->ray.dir.x * 0.1);
	pot_pos.x = old_pos_x;
	pot_pos.y = info->ray.pos.y - info->ray.dir.y * 0.2;
	if (info->ray.map[pot_pos.y][pot_pos.x] != 1 && info->ray.map[pot_pos.y][pot_pos.x] != 2)
		info->ray.pos.y -= (info->ray.dir.y * 0.1);
}
