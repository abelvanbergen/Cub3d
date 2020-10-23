/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_parse_elements.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 16:38:21 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/25 11:33:56 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_identifier(t_info *info, char **data, char *line)
{
	if (ft_strncmp("R", data[0], 2) == 0)
		get_resolution(data, &info->parse.res, &info->mlx, info->save);
	else if (ft_strncmp("S", data[0], 2) == 0)
		get_texture(info->mlx.mlx, data[0], line, &info->parse.sprite.tex);
	else if (ft_strncmp("NO", data[0], 3) == 0)
		get_texture(info->mlx.mlx, data[0], line, &info->parse.north_tex);
	else if (ft_strncmp("EA", data[0], 3) == 0)
		get_texture(info->mlx.mlx, data[0], line, &info->parse.east_tex);
	else if (ft_strncmp("SO", data[0], 3) == 0)
		get_texture(info->mlx.mlx, data[0], line, &info->parse.south_tex);
	else if (ft_strncmp("WE", data[0], 3) == 0)
		get_texture(info->mlx.mlx, data[0], line, &info->parse.west_tex);
	else if (ft_strncmp("C", data[0], 2) == 0)
		get_color(data, &info->parse.ceiling);
	else if (ft_strncmp("F", data[0], 2) == 0)
		get_color(data, &info->parse.floor);
	else
	{
		error_message2("Not all the elements are given",
											" or random element is given", 1);
	}
}

static int	ft_everything_set(t_info info)
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

void		ft_parse_file_elements(t_info *info, int fd)
{
	char	**data;
	char	*line;
	int		ret;

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
			if (data == 0)
				error_message1("ft_split failed", 1);
			get_identifier(info, data, line);
			free(line);
			ft_free_map_char(data);
			if (ft_everything_set(*info) == 1)
				break ;
		}
		else
			free(line);
	}
}
