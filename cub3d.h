/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 11:07:52 by avan-ber       #+#    #+#                */
/*   Updated: 2020/03/12 16:14:20 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdint.h>
# include "libft.h"
# include "get_next_line_bonus.h"
# include "mlx.h"
#include <math.h>
# include "vla.h"
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct	s_2doub
{
	double x;
	double y;
}				t_2doub;

typedef	struct	s_line
{
	int		length;
	int		start;
	int		end;
}				t_line;


typedef struct	s_ray
{
	int		**map;
	t_2int	pos_map;
	t_2doub pos;
	t_2doub	dir;
	t_2doub	plane;
	double	camera_x;
	t_2doub	ray_dir;
	t_2doub	delta_dist;
	t_2int	step;
	t_2doub	side_dist;
	int		hit;
	int		side;
	double	perp_wall_dist;
	t_line	line;
}				t_ray;

/*
** Cub3d enums -----------------------------------------------------------------
*/

/*
** Color enum, used to set the color in the right position in the int 0XAARRGGBB
*/
enum	e_color
{
	blue = 0,
	green = 1,
	red = 2,
	alpha = 3
};

/*
** Rotation enum, used to memorise the rotation of the player
*/
enum	e_rot
{
	north = 1,
	east = 2,
	south = 3,
	west = 4
};

/*
**==============================================================================
*/



/*
** Cub3d parse -----------------------------------------------------------------
*/

/*
** struct for all the needed info of a color element
*/
typedef struct		s_colorelem
{
	union
	{
		u_int32_t	mlx;
		u_int8_t	trgb[4];
	};
	bool			set;
}					t_colorelem;

/*
** struct for all the needed info of a texture element
*/
typedef struct	s_texelem
{
	void		*img;
	int			img_width;
	int			img_height;
	bool		set;
}				t_texelem;

/*
** struct for all the needed info of the resolution
*/
typedef struct	s_res
{
	int			x;
	int			y;
	bool		set;
}				t_res;

/*
** struct for the position of the player, with the coordinates and the rotation
*/
typedef	struct	s_posplayer
{
	t_2int		coor;
	int			rot;
	bool		set;
}				t_posplayer;

/*
** struct for the map, with a int_map, size and position player info
*/
typedef struct	s_map
{
	int			**map;
	t_2int		size;
	t_posplayer	posplayer;
}				t_map;

/*
** struct with every information you get out the Parsing
*/
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
}				t_info;

/*
**==============================================================================
*/


void			get_texture(void *mlx, char **texture, t_texelem *loc);
void			get_resolution(char **data, t_res *resolution, void *mlx);
void			get_color(char **data, t_colorelem *loc);
void			error_message1(char *message, int exitvalue);
void			error_message2(char *message1, char *message2, int exitvalue);
void			error_message3(char *message1, char *message2, char *message3,
																int exitvalue);
void			set_struct_info_zero(t_info *info);
int				ft_arraylen(char **data);
void			ft_fill_map(t_map *map, char **map_char);
void			ft_cub3d_raytrace(t_info info);

#endif
