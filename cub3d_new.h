/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_new.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/11 18:50:23 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/11 19:25:53 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_NEW_H
# define CUB3D__NEW_H

# include "libft.h"
# include "get_next_line_bonus.h"
# include "mlx.h"
# include "vla.h"

# include <math.h>
# include <stdint.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

/*
** Cub3d enums -----------------------------------------------------------------
*/

/*
** Cub3d color enum
*/
enum	e_color
{
	blue = 0,
	green = 1,
	red = 2,
	alpha = 3
};

/*
** Cub3d rotation enum
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
** Cub3d utils -----------------------------------------------------------------
*/

/*
** Cub3d utils 2 doubles
*/
typedef struct	s_2doub
{
	double x;
	double y;
}				t_2doub;

/*
**==============================================================================
*/



/*
** Cub3d Hooks -----------------------------------------------------------------
*/

/*
** Cub3d Hooks movement
*/
typedef struct	s_move
{
	bool		forward;
	bool		backword;
	bool		left;
	bool		right;
}				t_move;

/*
**==============================================================================
*/



/*
** Cub3d parsing ---------------------------------------------------------------
*/

/*
** Cub3d parsing resolution
*/
typedef struct	s_res
{
	int			x;
	int			y;
	bool		set;
}				t_res;

/*
** Cub3d parsing colorelement
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
** Cub3d parsing texture-element
*/
typedef struct	s_texelem
{
	void		*img;
	int			img_width;
	int			img_height;
	bool		set;
}				t_texelem;

/*
** Cub3d parsing map position player
*/
typedef	struct	s_posplayer
{
	t_2int		coor;
	int			rot;
	bool		set;
}				t_posplayer;

/*
** Cub3d parsing map
*/
typedef struct	s_map
{
	int			**map;
	t_2int		size;
	t_posplayer	posplayer;
}				t_map;

/*
** Cub3d parse info
*/
typedef struct	s_parse
{
	t_res			res;
	t_colorelem		floor;
	t_colorelem		ceiling;
	t_texelem		sprite_tex;
	t_texelem		north_tex;
	t_texelem		east_tex;
	t_texelem		south_tex;
	t_texelem		west_tex;
	t_map			map;
}				t_parse;

/*
**==============================================================================
*/



/*
** Cub3d raycasting ------------------------------------------------------------
*/


/*
** Cub3d raycasting info
*/
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

#endif
