/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_file.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 15:30:04 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/26 16:14:45 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_get_size_map_char(char **data, int *result_x, int *result_y)
{
	int x;
	int y;
	int	len;

	if (data[0])
	{
		x = ft_strlen(data[0]);
		y = 1;
	}
	else
		return (-1);
	while (data[y] != '\0')
	{
		len = ft_strlen(data[y]);
		if (len > x)
			x = len;
		y++;
	}
	*result_x = x;
	*result_y = y;
	return (0);
}

static int	ft_floodfill_8neighbors(int **map, t_2int size, int x, int y)
{
	int	i;
	int	j;

	if (x < 0 || x >= size.x || y < 0 || y >= size.y || map[y][x] == ' ')
		return (-1);
	else if (map[y][x] == 1)
		return (0);
	else
	{
		map[y][x] = 1;
		i = -1;
		while (i <= 1)
		{
			j = -1;
			while (j <= 1)
			{
				if ((i || j) && ft_floodfill_8neighbors(map, size, x + i, y + j)
																		== -1)
					return (-1);
				j++;
			}
			i++;
		}
		return (1);
	}
}

static void	ft_check_floodfill(t_info *info)
{
	int ret;
	int **map;

	map = ft_intmapdup(info->parse.map.map, info->parse.map.size);
	if (!map)
		error_message1("intmapdup failed, used for floodfill", 1);
	ret = ft_floodfill_8neighbors(map, info->parse.map.size,
			info->parse.map.posplayer.coor.x, info->parse.map.posplayer.coor.y);
	if (ret == -1)
		error_message1("The map is not closed", 1);
	ft_free_map_int(map, info->parse.map.size.y);
}

void		ft_parsefile(t_info *info, char *filename)
{
	int			fd;
	int			ret;
	t_vla_char	vla;

	fd = open(filename, O_RDONLY);
	ft_parse_file_elements(info, fd);
	if (ft_vla_char_init(&vla, 128) == -1)
		error_message1("ft_vla_char_init failed", 1);
	ft_parse_file_map(info, fd, &vla);
	close(fd);
	if (vla.current_elem == 0)
		error_message1("There is no map given", 1);
	if (ft_vla_char_resize(&vla) == -1)
		error_message1("ft_vla_char_resize failed", 1);
	ft_get_size_map_char(vla.map, &info->parse.map.size.x,
													&info->parse.map.size.y);
	ft_fill_map(&info->parse.map, vla.map, &info->parse.sprite.count);
	ft_free_map_char(vla.map);
	ft_check_floodfill(info);
	ft_set_pos_sprite(&info->parse.sprite, info->parse.map.map,
														info->parse.map.size);
}
