/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/05 08:59:55 by avan-ber       #+#    #+#                */
/*   Updated: 2020/03/05 09:10:11 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	main(void)
{
	t_info info;

	set_struct_info_zero(&info);

	printf("Floor mlx: %d\n", info.floor.mlx);
	printf("Floor set: %d\n", info.floor.set);
	printf("Ceiling mlx: %d\n", info.ceiling.mlx);
	printf("Ceiling set: %d\n", info.ceiling.set);

	printf("Res x: %d\n", info.res.x);
	printf("Res y: %d\n", info.res.y);
	printf("Res set: %d\n", info.res.set);

	printf("Sprite ptr: %p\n", info.sprite_tex.img);
	printf("Sprite img_width: %d\n", info.sprite_tex.img_width);
	printf("Sprite img_height: %d\n", info.sprite_tex.img_height);
	printf("Sprite set: %d\n", info.sprite_tex.set);

	printf("north ptr: %p\n", info.north_tex.img);
	printf("north img_width: %d\n", info.north_tex.img_width);
	printf("north img_height: %d\n", info.north_tex.img_height);
	printf("north set: %d\n", info.north_tex.set);

	printf("east ptr: %p\n", info.east_tex.img);
	printf("east img_width: %d\n", info.east_tex.img_width);
	printf("east img_height: %d\n", info.east_tex.img_height);
	printf("east set: %d\n", info.east_tex.set);

	printf("south ptr: %p\n", info.south_tex.img);
	printf("south img_width: %d\n", info.south_tex.img_width);
	printf("south img_height: %d\n", info.south_tex.img_height);
	printf("south set: %d\n", info.south_tex.set);

	printf("west ptr: %p\n", info.west_tex.img);
	printf("west img_width: %d\n", info.west_tex.img_width);
	printf("west img_height: %d\n", info.west_tex.img_height);
	printf("west set: %d\n", info.west_tex.set);

	return(0);
}
