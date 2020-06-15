/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hooks.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/11 14:28:44 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/15 19:05:15 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define W_KEY 13
#define S_KEY 1
#define A_KEY 0
#define D_KEY 2
#define LEFT_ARROW_KEY 123
#define RIGHT_ARROW_KEY 124
#define ESC_KEY 53
#define	LEFT -0.02
#define	RIGHT 0.02

int		ft_key_press(int keycode, t_move *move)
{
	if (keycode == W_KEY)
		move->forward = 1;
	if (keycode == S_KEY)
		move->backword = 1;
	if (keycode == A_KEY)
		move->left = 1;
	if (keycode == D_KEY)
		move->right = 1;
	if (keycode == LEFT_ARROW_KEY)
		move->rot_left = 1;
	if (keycode == RIGHT_ARROW_KEY)
		move->rot_right = 1;
	return (0);
}

int		ft_key_release(int keycode, t_move *move)
{
	if (keycode == W_KEY)
		move->forward = 0;
	if (keycode == S_KEY)
		move->backword = 0;
	if (keycode == A_KEY)
		move->left = 0;
	if (keycode == D_KEY)
		move->right = 0;
	if (keycode == LEFT_ARROW_KEY)
		move->rot_left = 0;
	if (keycode == RIGHT_ARROW_KEY)
		move->rot_right = 0;
	return (0);
}

void	ft_rotate(double rot, t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->ray.dir.x;
	info->ray.dir.x = (info->ray.dir.x * cos(rot)) - (info->ray.dir.y * sin(rot));
	info->ray.dir.y = (old_dir_x * sin(rot)) + (info->ray.dir.y * cos(rot));
	old_dir_x = info->ray.plane.x;
	info->ray.plane.x = (info->ray.plane.x * cos(rot)) - (info->ray.plane.y * sin(rot));
	info->ray.plane.y = (old_plane_x * sin(rot)) + (info->ray.plane.y * cos(rot));
	ft_make_frame(info);
}

int		ft_process_movement(t_info *info)
{
	if (info->move.forward == 1)
	{
		info->ray.pos.x += (info->ray.dir.x * 0.1);
		info->ray.pos.y += (info->ray.dir.y * 0.1);
		ft_make_frame(info);
	}
	if (info->move.backword == 1)
	{
		info->ray.pos.x -= (info->ray.dir.x * 0.1);
		info->ray.pos.y -= (info->ray.dir.y * 0.1);
		ft_make_frame(info);
	}
	if (info->move.left == 1)
	{
		info->ray.pos.x += (info->ray.dir.y * 0.1);
		info->ray.pos.y -= (info->ray.dir.x * 0.1);
		ft_make_frame(info);
	}
	if (info->move.right == 1)
	{
		info->ray.pos.x -= (info->ray.dir.y * 0.1);
		info->ray.pos.y += (info->ray.dir.x * 0.1);
		ft_make_frame(info);
	}
	if (info->move.rot_left == 1)
		ft_rotate(LEFT, info);
	if (info->move.rot_right == 1)
		ft_rotate(RIGHT, info);
	return (0);
}
