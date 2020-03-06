/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_file.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 15:30:04 by avan-ber       #+#    #+#                */
/*   Updated: 2020/03/06 17:50:12 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_struct_colorelem_zero(t_colorelem *color)
{
	color->mlx = 0;
	color->set = 0;
}

static void	set_struct_res_zero(t_res *res)
{
	res->x = 0;
	res->y = 0;
	res->set = 0;
}

static void	set_struct_texelem_zero(t_texelem *tex)
{
	tex->img = 0;
	tex->img_height = 0;
	tex->img_width = 0;
	tex->set = 0;
}

void	set_struct_info_zero(t_info *info)
{
	set_struct_res_zero(&info->res);
	set_struct_colorelem_zero(&info->floor);
	set_struct_colorelem_zero(&info->ceiling);
	set_struct_texelem_zero(&info->sprite_tex);
	set_struct_texelem_zero(&info->north_tex);
	set_struct_texelem_zero(&info->east_tex);
	set_struct_texelem_zero(&info->south_tex);
	set_struct_texelem_zero(&info->west_tex);
}

void	get_identifier(t_info *info, char **data)
{
	if (ft_strncmp("R", data[0], 2) == 0)
		get_resolution(data, &info->res);
	else if (ft_strncmp("S", data[0], 2) == 0)
		get_texture(info->mlx, data, &info->sprite_tex);
	else if (ft_strncmp("NO", data[0], 3) == 0)
		get_texture(info->mlx, data, &info->north_tex);
	else if (ft_strncmp("EA", data[0], 3) == 0)
		get_texture(info->mlx, data, &info->east_tex);
	else if (ft_strncmp("SO", data[0], 3) == 0)
		get_texture(info->mlx, data, &info->south_tex);
	else if (ft_strncmp("WE", data[0], 3) == 0)
		get_texture(info->mlx, data, &info->west_tex);
	else if (ft_strncmp("C", data[0], 2) == 0)
		get_color(data, &info->ceiling);
	else if (ft_strncmp("F", data[0], 2) == 0)
		get_color(data, &info->floor);
	else if (data[0])
		error_message1("There is a line that is not a element or a empty \
																	line\n", 1);
}

int		ft_everything_set(t_info info)
{
	if (info.res.set == 0)
		return (0);
	if (info.north_tex.set == 0)
		return (0);
	if (info.east_tex.set == 0)
		return (0);
	if (info.south_tex.set == 0)
		return (0);
	if (info.west_tex.set == 0)
		return (0);
	if (info.floor.set == 0)
		return (0);
	if (info.ceiling.set == 0)
		return (0);
	if (info.sprite_tex.set == 0)
		return (0);
	return (1);
}

void	ft_print_data(char **data)
{
	int i;

	i = 0;
	while (data[i])
	{
		printf("%s\n", data[i]);
		i++;
	}
}

void	ft_parsefile(t_info *info, char *filename)
{
	int			fd;
	int			ret;
	char		*line;
	char		**data;
	bool		new_line;
	bool		new_line_last;
	t_vla_char	vla;

	fd = open(filename, O_RDONLY);
	// while (1)
	// {
	// 	ret = get_next_line(fd, &line);
	// 	if (ret == -1)
	// 		error_message1("Get_next_line failed", 1);
	// 	if (ret == 0)
	// 	{
	// 		free(line);
	// 		error_message1("File is incomplete", 1);
	// 	}
	// 	data = ft_split(line, ' ');
	// 	free(line);
	// 	if (data == 0)
	// 	{
	// 		error_message1("ft_split failed", 1);
	// 	}
	// 	get_identifier(info, data);
	// 	ft_free_map_char(data, ft_arraylen(data));
	// 	if (ft_everything_set(*info) == 1)
	// 		break ;
	// }
	if (ft_vla_char_init(&vla, 16) == -1)
		error_message1("ft_vla_char_init failed", 1);
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			error_message1("Get_next_line failed", 1);
		if (!*line)
		{
			if (new_line && !new_line_last)
				error_message1("There is a newline in your map", 1);
			else
			{
				new_line = true;
				new_line_last = true;
			}
		}
		else
		{
			new_line_last = 0;
			ft_vla_char_add_element(&vla, line);
		}
		if (ret == 0)
			break ;
	}
	ft_vla_char_resize(&vla);
	ft_print_data(vla.map);
	ft_get_size_array(vla.map);
}

int	main(int ac, char **av)
{
	t_info	info;

	info.mlx = mlx_init();
	ft_parsefile(&info, av[1]);
}
