/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_file.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 15:30:04 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/22 17:42:46 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_identifier(t_info *info, char **data)
{
	if (ft_strncmp("R", data[0], 2) == 0)
		get_resolution(data, &info->parse.res, &info->mlx);
	else if (ft_strncmp("S", data[0], 2) == 0)
		get_texture(info->mlx.mlx, data, &info->parse.sprite.tex);
	else if (ft_strncmp("NO", data[0], 3) == 0)
		get_texture(info->mlx.mlx, data, &info->parse.north_tex);
	else if (ft_strncmp("EA", data[0], 3) == 0)
		get_texture(info->mlx.mlx, data, &info->parse.east_tex);
	else if (ft_strncmp("SO", data[0], 3) == 0)
		get_texture(info->mlx.mlx, data, &info->parse.south_tex);
	else if (ft_strncmp("WE", data[0], 3) == 0)
		get_texture(info->mlx.mlx, data, &info->parse.west_tex);
	else if (ft_strncmp("C", data[0], 2) == 0)
		get_color(data, &info->parse.ceiling);
	else if (ft_strncmp("F", data[0], 2) == 0)
		get_color(data, &info->parse.floor);
	else
		error_message1("Not all the elements are given", 1);
}

int		ft_everything_set(t_info info)
{
	if (info.parse.res.set == 0)
		return (0);
	if (info.parse.north_tex.set == 0)
		return (0);
	if (info.parse.east_tex.set == 0)
		return (0);
	if (info.parse.south_tex.set == 0)
		return (0);
	if (info.parse.west_tex.set == 0)
		return (0);
	if (info.parse.floor.set == 0)
		return (0);
	if (info.parse.ceiling.set == 0)
		return (0);
	if (info.parse.sprite.tex.set == 0)
		return (0);
	return (1);
}

int	ft_get_size_map_char(char **data, int *result_x, int *result_y)
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

int	ft_floodfill_8neighbors(int **map, t_2int size, int x, int y)
{
	int	i;
	int	j;

	if (x < 0 || x >= size.x || y < 0 || y >= size.y || map[y][x] == ' ')
	{
		printf("het is de eertse check\n");
		return (-1);
	}
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

void	ft_print_map_int(int **map, int y, int x)
{
	int i;
	int j;

	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			printf("%2d", map[j][i]);
			i++;
		}
		j++;
		printf("\n");
	}
}

void	ft_parsefile(t_info *info, char *filename)
{
	int			fd;
	int			ret;
	char		*line;
	char		**data;
	int			begin_map;
	t_vla_char	vla;

	fd = open(filename, O_RDONLY);
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			error_message1("Get_next_line failed", 1);
		if (ret == 0)
			error_message1("File is incomplete", 1);
		if (*line)
		{
			data = ft_split(line, ' ');
			free(line);
			if (data == 0)
				error_message1("ft_split failed", 1);
			get_identifier(info, data);
			ft_free_map_char(data);
			if (ft_everything_set(*info) == 1)
				break ;
		}
		else
			free(line);
	}
	begin_map = 0;
	if (ft_vla_char_init(&vla, 16) == -1)
		error_message1("ft_vla_char_init failed", 1);
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			error_message1("Get_next_line failed", 1);
		if (*line)
		{
			if (begin_map == 2)
				error_message1("There is a newline in your map", 1);
			begin_map = 1;
			ft_vla_char_add_element(&vla, line);
		}
		else
		{
			free(line);
			if (begin_map == 1)
				begin_map = 2;
		}
		if (ret == 0)
			break ;
	}
	close(fd);
	if (vla.current_elem == 0)
		error_message1("There is no map given", 1);
	if (ft_vla_char_resize(&vla) == -1)
		error_message1("ft_vla_char_resize failed", 1);
	ft_get_size_map_char(vla.map, &info->parse.map.size.x, &info->parse.map.size.y);
	ft_fill_map(&info->parse.map, vla.map, &info->parse.sprite.count);
	ft_free_map_char(vla.map);
	ret = ft_floodfill_8neighbors(ft_intmapdup(info->parse.map.map, info->parse.map.size),
		info->parse.map.size, info->parse.map.posplayer.coor.x, info->parse.map.posplayer.coor.y);
	if (ret == -1)
		error_message1("The map is not closed", 1);
	ft_set_pos_sprite(&info->parse.sprite, info->parse.map.map,
														info->parse.map.size);
	printf("Parse is compleet!\n");
}

int	main(int ac, char **av)
{
	t_info	info;

	ft_bzero(&info, sizeof(t_info));
	info.mlx.mlx = mlx_init();
	ft_parsefile(&info, av[1]);
	ft_cub3d_raytrace(info);
	return (0);
}
