/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hooks.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/11 14:28:44 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/26 17:43:41 by avan-ber      ########   odam.nl         */
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
#define LEFT -0.04
#define RIGHT 0.04

int	ft_close_screen(t_info *info)
{
	mlx_destroy_image(info->mlx.mlx, info->img.one.img);
	mlx_destroy_image(info->mlx.mlx, info->img.two.img);
	mlx_destroy_window(info->mlx.mlx, info->mlx.mlx_window);
	exit(1);
	return (0);
}

int	ft_key_press(int keycode, t_info *info)
{
	if (keycode == W_KEY)
		info->move.forward = 1;
	if (keycode == S_KEY)
		info->move.backward = 1;
	if (keycode == A_KEY)
		info->move.left = 1;
	if (keycode == D_KEY)
		info->move.right = 1;
	if (keycode == LEFT_ARROW_KEY)
		info->move.rot_left = 1;
	if (keycode == RIGHT_ARROW_KEY)
		info->move.rot_right = 1;
	if (keycode == ESC_KEY)
		ft_close_screen(info);
	return (0);
}

int	ft_key_release(int keycode, t_move *move)
{
	if (keycode == W_KEY)
		move->forward = 0;
	if (keycode == S_KEY)
		move->backward = 0;
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

int	ft_process_movement(t_info *info)
{
	if (info->move.forward == 1)
		ft_move_forward(info);
	if (info->move.backward == 1)
		ft_move_backward(info);
	if (info->move.left == 1)
		ft_move_left(info);
	if (info->move.right == 1)
		ft_move_right(info);
	if (info->move.rot_left == 1)
		ft_rotate(LEFT, info);
	if (info->move.rot_right == 1)
		ft_rotate(RIGHT, info);
	if (info->move.forward == 1 || info->move.backward == 1 ||
					info->move.left == 1 || info->move.right == 1 ||
						info->move.rot_left == 1 || info->move.rot_right == 1)
	{
		ft_make_frame(info);
	}
	return (0);
}
