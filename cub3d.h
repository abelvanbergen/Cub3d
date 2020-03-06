/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 11:07:52 by avan-ber       #+#    #+#                */
/*   Updated: 2020/03/06 17:56:33 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdint.h>
# include "libft.h"
# include "get_next_line_bonus.h"
# include "mlx.h"
# include "vla.h"
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

enum	e_color
{
	blue = 0,
	green = 1,
	red = 2,
	alpha = 3
};

typedef struct		s_colorelem
{
	union
	{
		u_int32_t	mlx;
		u_int8_t	trgb[4];
	};
	bool			set;
}					t_colorelem;

typedef struct	s_res
{
	int			x;
	int			y;
	bool		set;
}				t_res;

typedef struct	s_texelem
{
	void		*img;
	int			img_width;
	int			img_height;
	bool		set;
}				t_texelem;

typedef	struct	s_coor
{
	int			x;
	int			y;
}				t_coor;

typedef struct	s_map
{
	int			**map;
	t_coor		size;
}				t_map;

typedef struct	s_info
{
	void			*mlx;
	t_res			res;
	t_colorelem		floor;
	t_colorelem		ceiling;
	t_texelem		sprite_tex;
	t_texelem		north_tex;
	t_texelem		east_tex;
	t_texelem		south_tex;
	t_texelem		west_tex;
	t_map			map;
	bool			set;
}				t_info;



void			get_texture(void *mlx, char **texture, t_texelem *loc);
void			get_resolution(char **data, t_res *resolution);
void			get_color(char **data, t_colorelem *loc);
void			error_message1(char *message, int exitvalue);
void			error_message2(char *message1, char *message2, int exitvalue);
void			error_message3(char *message1, char *message2, char *message3,
																int exitvalue);
void			set_struct_info_zero(t_info *info);
int				ft_arraylen(char **data);

#endif
