#include "libft.h"
#include "get_next_line_bonus.h"
#include "mlx.h"
#include <stdio.h>
#include <stdint.h>

enum	e_color
{
	blue = 0,
	green = 1,
	red = 2,
	alpha = 3
};

typedef union	u_color
{
	u_int32_t	mlx;
	u_int8_t	trgb[4];
}				t_color;

typedef struct	s_res
{
	int			x;
	int			y;
}				t_res;

typedef struct	s_info
{
	t_res		res;
	t_color		color_f;
	t_color		color_c;
	char		*sprite_text;
	char		*north_text;
	char		*east_text;
	char		*south_text;
	char		*west_text;
}				t_info;

void	error_message(char *message)
{
	write(1, "error\n", 6);
	write(1, message, ft_strlen(message));
}

int	check_file_name(char *filename, char *end, int len)
{
	int	strlen_filename;

	strlen_filename = ft_strlen(filename);
	while (len > 0)
	{
		if (filename[strlen_filename - 1] != end[len - 1])
			return (-1);
		len--;
		strlen_filename--;
	}
	return (1);
}

int		ft_isidentifier(char *str)
{
	if (str[0] == 'N' && str[1] == 'O' && str[2] == '\0')
		return (1);
	if (str[0] == 'E' && str[1] == 'A' && str[2] == '\0')
		return (2);
	if (str[0] == 'S' && str[1] == 'O' && str[2] == '\0')
		return (3);
	if (str[0] == 'W' && str[1] == 'E' && str[2] == '\0')
		return (4);
	if (str[0] == 'R' && str[1] == '\0')
		return (5);
	if (str[0] == 'S' && str[1] == '\0')
		return (6);
	if (str[0] == 'F' && str[1] == '\0')
		return (7);
	if (str[0] == 'C' && str[1] == '\0')
		return (8);
	return (0);
}

void	set_struct_info_zero(t_info *info)
{
	info->north_text = 0;
	info->east_text = 0;
	info->south_text = 0;
	info->west_text = 0;
	info->sprite_text = 0;
	info->res.x = 0;
	info->res.y = 0;
	info->color_c.mlx = 0;
	info->color_f.mlx = 0;
}

int	ft_arraylen(char **data)
{
	int i;

	i = 0;
	while (data[i] != '\0')
		i++;
	return (i);
}

char	*get_texture(char **array)
{
	if (ft_arraylen(array) != 2)
		return(0);
}

int	get_info_identifier_north(t_info *info, )

int	get_info_identifier(t_info *info, char **array, int id_id)
{
	if (id_id == 1)
	{
		if (info->north_text != 0)
		{
			error_message("There are to many North Textures\n");
			return (-1);
		}
		info->north_text = get_texture(array);
	}
	if (id_id == 2)
	{
		if (info->north_text != 0)
		{
			error_message("There are to many North Textures\n");
			return (-1);
		}
		info->north_text = get_texture(array);
		if (info->north_text == 0)
		{
			error_message("The information is not ")
		}
	}
}

void	ft_parse_file(char *filename, *)
{
	int		ret;
	int		fd;
	char	*line;
	int		map;
	char	**array;
	t_info	info;

	fd = open(filename);
	set_struct_info_zero(&info);
	while (1)
	{
		ret = get_next_line(fd, line);
		if (ret < 1)
		{
			if (ret == 0)
				error_message("No information in the inputfile\n");
			if (ret == -1)
				error_message("Get_next_line fails\n");
			close(filename);
			return (-1);
		}
		array = ft_split(line, ' ');
		if (array == 0)
		{
			error_message("split fails\n");
			close(filename);
			return (-1);
		}
		if (ft_isidentifier(array[0]) > 1 || ft_strncmp(array[0], "\0", 1) == 0)
		{
			if (ft_isidentifier(array[0]) > 1)
				get_info_identifier(&info, array, ft_isidentifier(array[0]));
		}
		else
			break ;
	}
	if (ft_check_all_info(info) == -1)
	{
		error_message("Inputfile has not enough information");
		return (-1)
	}
	while(1)
	{

	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (check_file_name(av[1], ".cub", 4) == 1)
			ft_parse_file(av[1]);
		else
			error_message("file has invalid name\n");
	}
	else
		error_message("no valid input given\n");
}
