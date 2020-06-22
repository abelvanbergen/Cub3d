/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 16:12:40 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/19 17:09:07 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "stdbool.h"
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

int last = 0;

typedef struct  s_imginfo
{
	void		*mlx;
	void		*new_window;
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

void	*ft_img_set(void *b, unsigned int c, size_t len)
{
	unsigned int	*buf;
	size_t			i;

	buf = (unsigned int*)b;
	i = 0;
	while (i < len)
	{
		buf[i] = c;
		i++;
	}
	return (b);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

int	ft_swapimg(int keycode, void *data)
{
	printf("we zijn in swapimage\n");
	fflush(0);

	t_imginfo img = (*(t_imginfo*)(data));
	void	*temp;

	keycode = 0;
	temp = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	if (last)
	{
		ft_img_set(temp, 0, img.line_length * 150);
		mlx_put_image_to_window(img.mlx, img.new_window, img.img, 0, 0);
	}
	else
	{
		ft_img_set(temp, 0xFF, img.line_length * 75);
		ft_img_set(temp + img.line_length * 300, 0xFF00, img.line_length * 75);
		mlx_put_image_to_window(img.mlx, img.new_window, img.img, 0, 0);
	}
	last = !last;
	return (0);
}

int main(void)
{
	t_imginfo		img;

	img.mlx = mlx_init();
	img.new_window = mlx_new_window(img.mlx, 600, 600, "texture test");
	img.img = mlx_new_image(img.mlx, 600, 600);
	printf("voorbij 1\n\n");
	mlx_hook(img.new_window, 2, 1L << 0, ft_swapimg, &img);
	mlx_loop(img.mlx);
}
