/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 16:12:40 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/16 18:09:24 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "stdbool.h"
#include <stdio.h>
#include <unistd.h>

typedef struct  s_imginfo
{
    void		*img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_imginfo;

typedef struct	s_texelem
{
	void		*img;
	void		*addr;
	int			img_width;
	int			img_height;
	int			bpp;
	int			size_line;
	int			endian;
	bool		set;
}				t_texelem;

void			my_mlx_pixel_put(t_imginfo *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void			ft_get_color(t_texelem img, int x, int y, unsigned int *color)
{
	char	*dst;

	dst = img.addr + (y * img.size_line + x * (img.bpp / 8));
	color = (unsigned int*)dst;
}

int main(int ac, char **av)
{
	void			*mlx;
	void			*new_window;
	t_texelem		tex;
	t_imginfo		img;
	int				i;
	int				j;
	unsigned int	color;

	ac = 0;
	mlx = mlx_init();
	printf("fout pad\n\n");
	tex.img = mlx_png_file_to_image(mlx, av[1], &tex.img_width, &tex.img_height);
	if (tex.img == 0)
		printf("fout pad\n");
	tex.addr = mlx_get_data_addr(tex.img, &tex.bpp, &tex.size_line, &tex.endian);
	new_window = mlx_new_window(mlx, tex.img_width, tex.img_height, "texture test");
	img.img = mlx_new_image(mlx, tex.img_width, tex.img_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	j = 0;
	while (j < tex.img_height)
	{
		i = 0;
		while (i < tex.img_width)
		{
			color = *(unsigned int*)(tex.addr + (j * tex.size_line + i * (tex.bpp / 8)));
			printf("%x\n", color);
			my_mlx_pixel_put(&img, i, j, color);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(mlx, new_window, tex.img, 0, 0);
	mlx_loop(mlx);
}