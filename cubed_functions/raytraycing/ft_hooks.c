/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hooks.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/11 14:28:44 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/11 18:30:34 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define W_KEY 13
#define S_KEY 1
#define A_KEY 0
#define D_KEY 2

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
	return (0);
}

int		ft_process_movement(t_info info, t_move move)
{
	if (move.forward == 1)
	{
		info.map.posplayer.coor.x -= 1;
	}
	if (move.backword == 1)
	{
		info.map.posplayer.coor.x += 1;
	}
	return (0);
}
