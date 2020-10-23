/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/11 18:50:23 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/26 17:47:53 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "get_next_line_bonus.h"
# include "mlx.h"
# include "vla.h"

# include <math.h>
# include <stdint.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>


/*
** Cub3d enums -----------------------------------------------------------------
*/

/*
** Cub3d color enum
*/
enum				e_color
{
	blue = 0,
	green = 1,
	red = 2,
	alpha = 3
};

/*
** Cub3d rotation enum
*/
enum				e_rot
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
typedef struct		s_2doub
{
	double			x;
	double			y;
}					t_2doub;

/*
** Cub3d utils image elem
*/
typedef struct  	s_imginfo
{
    void			*img;
    char        	*addr;
    int         	bits_per_pixel;
    int         	line_length;
    int         	endian;
	int				img_width;
	int				img_height;
	bool			set;
}					t_imginfo;

/*
**==============================================================================
*/



/*
** Cub3d BMP image--------------------------------------------------------------
*/

/*
** Cub3d BMP image header
*/
# pragma pack(push, 1)
typedef struct					s_bmpheader
{
	uint16_t					type;
	uint32_t					size;
	uint16_t					reserved1;
	uint16_t					reserved2;
	uint32_t					offset;
	uint32_t					dib_header_size;
	int32_t						width_px;
	int32_t						height_px;
	uint16_t					num_planes;
	uint16_t					bits_per_pixel;
	uint32_t					compression;
	uint32_t					image_size_bytes;
	int32_t						x_resolution_ppm;
	int32_t						y_resolution_ppm;
	uint32_t					num_colors;
	uint32_t					important_colors;
}								t_bmpheader;

/*
** Cub3d BMP image ifo
*/
typedef struct					s_bmpimage
{
	t_bmpheader					header;
	unsigned char				*data;
	size_t						datasize;
	int							padding;
	int							linesize;
	int							bits_per_pixel;
}								t_bmpimage;
# pragma pack(pop)

/*
**==============================================================================
*/



/*
** Cub3d Hooks -----------------------------------------------------------------
*/

/*
** Cub3d Hooks movement
*/
typedef struct		s_move
{
	bool			forward;
	bool			backward;
	bool			left;
	bool			right;
	bool			rot_left;
	bool			rot_right;
}					t_move;

/*
**==============================================================================
*/



/*
** Cub3d Sprite casting --------------------------------------------------------
*/

/*
** Cub3d sprite utils
*/
typedef struct	s_s_utils
{
	double			invdet;
	t_2doub			transform;
	t_2doub			sprite;
	int				spritescreenx;
	int 			sprite_width;
	int				sprite_height;
	t_2int			drawstart;
	t_2int			drawend;
	t_2int			tex;
	int				d;
	int 			color;
}					t_s_utils;

/*
**==============================================================================
*/



/*
** Cub3d parsing ---------------------------------------------------------------
*/

/*
** Cub3d parsing resolution
*/
typedef struct		s_res
{
	int				x;
	int				y;
	bool			set;
}					t_res;

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
** Cub3d parsing map position player
*/
typedef	struct		s_posplayer
{
	t_2int			coor;
	int				rot;
	bool			set;
}					t_posplayer;

/*
** Cub3d parsing map
*/
typedef struct		s_map
{
	int				**map;
	t_2int			size;
	t_posplayer		posplayer;
}					t_map;

/*
** Cub3d parsing sprite position info
*/
typedef struct		s_sprite_pos
{
	t_2doub			coor;
	double			distance;
}					t_sprite_pos;

/*
** Cub3d parsing sprite info
*/
typedef struct		s_sprite
{
	t_imginfo		tex;
	int				count;
	t_sprite_pos	*pos;
}					t_sprite;


/*
** Cub3d parse info
*/
typedef struct	s_parse
{
	t_res		res;
	t_colorelem	floor;
	t_colorelem	ceiling;
	t_sprite	sprite;
	t_imginfo	north_tex;
	t_imginfo	east_tex;
	t_imginfo	south_tex;
	t_imginfo	west_tex;
	t_map		map;
}				t_parse;

/*
**==============================================================================
*/



/*
** Cub3d raycasting ------------------------------------------------------------
*/

/*
** Cub3d raycasting line to draw
*/
typedef	struct	s_line
{
	int			length;
	int			start;
	int			end;
}				t_line;

/*
** Cub3d raycasting info
*/
typedef struct	s_ray
{
	int			**map;
	t_2int		pos_map;
	t_2doub 	pos;
	t_2doub		dir;
	t_2doub		plane;
	double		camera_x;
	t_2doub		ray_dir;
	t_2doub		delta_dist;
	t_2int		step;
	t_2doub		side_dist;
	int			hit;
	int			side;
	double		perp_wall_dist;
	t_line		line;
	double		wall_x;
	double		*zbuffer;
}				t_ray;

/*
**==============================================================================
*/



/*
** Cub3d image -----------------------------------------------------------------
*/

/*
** Cub3d image info
*/
typedef struct	s_img
{
	t_imginfo	one;
	t_imginfo	two;
	int			count;
}				t_img;
/*
**==============================================================================
*/



/*
** Cub3d mlx -------------------------------------------------------------------
*/

/*
** Cub3d mlx info
*/
typedef struct  s_mlx
{
	void		*mlx;
	void		*mlx_window;
}               t_mlx;

/*
**==============================================================================
*/



/*
** Cub3d info ------------------------------------------------------------------
*/

/*
** Cub3d info
*/
typedef struct  s_info
{
	t_ray		ray;
	t_mlx		mlx;
	t_parse		parse;
	t_img		img;
	t_move		move;
	bool		save;
}               t_info;

/*
**==============================================================================
*/



/*
** Cub3d prototypes ------------------------------------------------------------
*/

void			error_destroy(t_info *info, char *message);
void			ft_make_screen_shot(t_info *info);
void			ft_start(t_info *info);
void			ft_draw_texture(t_info *info, t_imginfo texture,
														t_imginfo *img, int x);
void			ft_draw_sprite(t_info *info, t_imginfo *new_img);
void			my_mlx_pixel_put(t_imginfo *img, int x, int y, int color);
void			ft_sort_sprite_distance(t_sprite_pos *sprite_pos,
															int sprite_count);
void			ft_set_pos_sprite(t_sprite *sprite, int **map, t_2int map_size);
void			ft_put_texture(t_info *info, t_imginfo *img, int x);
void			my_mlx_pixel_put(t_imginfo *img, int x, int y, int color);
void			ft_get_texture(t_info *info);
int				ft_close_screen(t_info *info);
void			ft_rotate(double rot, t_info *info);
void			ft_move_forward(t_info *info);
void			ft_move_backward(t_info *info);
void			ft_move_left(t_info *info);
void			ft_move_right(t_info *info);
void			ft_make_frame(t_info *info);
int				ft_key_press(int keycode, t_info *info);
int				ft_key_release(int keycode, t_move *move);
int				ft_process_movement(t_info *info);
void			get_texture(void *mlx, char *rot, char *line, t_imginfo *loc);
void			get_resolution(char **data, t_res *resolution, void *mlx,
																	bool save);
void			get_color(char **data, t_colorelem *loc);
void			error_message1(char *message, int exitvalue);
void			error_message2(char *message1, char *message2, int exitvalue);
void			error_message3(char *message1, char *message2, char *message3,
																int exitvalue);
void			set_struct_info_zero(t_info *info);
int				ft_arraylen(char **data);
void			ft_fill_map(t_map *map, char **map_char, int *sprite_count);
void			ft_cub3d_raytrace(t_info info);
void			ft_parse_file_elements(t_info *info, int fd);
void			ft_parse_file_map(t_info *info, int fd, t_vla_char *vla);
void			ft_parsefile(t_info *info, char *filename);
void			ft_sort_sprite_distance(t_sprite_pos *sprite_pos,
															int sprite_count);

/*
**==============================================================================
*/

#endif
