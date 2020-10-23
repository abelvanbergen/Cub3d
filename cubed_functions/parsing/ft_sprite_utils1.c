/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sprite_utils1.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 17:04:11 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/26 16:19:23 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_set_pos_sprite(t_sprite *sprite, int **map, t_2int map_size)
{
	int i;
	int j;
	int k;

	sprite->pos = ft_calloc(sprite->count, sizeof(t_sprite_pos));
	if (!sprite->pos)
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

static void	ft_swap_sprite_info(t_sprite_pos *a, t_sprite_pos *b)
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

void		ft_sort_sprite_distance(t_sprite_pos *sprite_pos, int sprite_count)
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
