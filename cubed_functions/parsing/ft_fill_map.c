/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fill_map.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 16:35:16 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/18 14:06:55 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_get_char_enum_rot(int id)
{
	if (id == 1)
		return ("N");
	else if (id == 2)
		return ("E");
	else if (id == 3)
		return ("S");
	else
		return ("W");
}

static int	ft_set_posplayer(t_map *map, int rot, t_2int coor)
{
	if (map->posplayer.set == 1)
		error_message2("There are multiple players given\n\
						Second appearance: ", ft_get_char_enum_rot(rot), 1);
	map->posplayer.set = 1;
	map->posplayer.coor.x = coor.x;
	map->posplayer.coor.y = coor.y;
	map->posplayer.rot = rot;
	return (9);
}

static int	ft_fill_map_get_int(char c, t_map *map, t_2int coor)
{
	if (c == '1')
		return (1);
	else if (c == '2')
		return (2);
	else if (c == '0')
		return (0);
	else if (c == ' ')
		return (' ');
	else if (c == 'N')
		return (ft_set_posplayer(map, north, coor));
	else if (c == 'E')
		return (ft_set_posplayer(map, east, coor));
	else if (c == 'S')
		return (ft_set_posplayer(map, south, coor));
	else if (c == 'W')
		return (ft_set_posplayer(map, west, coor));
	else
		error_message2("There is a invalid char in the map\nChar: ",
									&c, 1);
	return (0);
}

void	ft_fill_map(t_map *map, char **map_char)
{
	t_2int		coor;
	int			row_len;

	printf("map->size.y: %d\nmap->size.x: %d\n", map->size.y, map->size.x);
	map->map = ft_make_map_int(map->size.y, map->size.x);
	if (!map)
		error_message1("ft_make_map_int failed", 1);
	coor.y = 0;
	while (coor.y < map->size.y)
	{
		coor.x = 0;
		row_len = ft_strlen(map_char[coor.y]);
		while (coor.x < map->size.x)
		{
			if (coor.x < row_len)
				map->map[coor.y][coor.x] = \
					ft_fill_map_get_int(map_char[coor.y][coor.x], map, coor);
			else
				map->map[coor.y][coor.x] = ' ';
			coor.x++;
		}
		coor.y++;
	}
	if (map->posplayer.set == 0)
		error_message1("There is not a startposition for the player", 1);
}
