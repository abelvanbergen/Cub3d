/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_screen_shot.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/25 13:50:43 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/26 17:53:15 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_make_header(t_info *info, t_bmpheader *header, int linesize)
{
	header->type = 0x4d42;
	header->image_size_bytes = (linesize * info->parse.res.y);
	header->size = (linesize * info->parse.res.y) + 54;
	header->offset = 54;
	header->dib_header_size = 40;
	header->width_px = info->parse.res.x;
	header->height_px = info->parse.res.y;
	header->num_planes = 1;
	header->bits_per_pixel = 24;
}

static void	ft_write_color_bmp(t_info *info, int fd, int padding)
{
	int		x;
	int		y;
	char	*color;
	char	*data;

	y = info->parse.res.y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < info->parse.res.x)
		{
			color = (info->img.one.addr + (y * info->img.one.line_length
									+ x * (info->img.one.bits_per_pixel / 8)));
			if (write(fd, color, 3) == -1)
				error_destroy(info, "write failed");
			x++;
		}
		if (write(fd, "\0\0\0\0", padding) == -1)
			error_destroy(info, "write failed");
		y--;
	}
}

void		ft_make_screen_shot(t_info *info)
{
	int			fd;
	t_bmpimage	bmpimage;

	fd = open("screenshot.bmp", O_RDWR | O_TRUNC | O_CREAT, 0755);
	if (fd < 0)
		error_message1("making fill for screenshot failed", 1);
	info->img.one.img = mlx_new_image(info->mlx.mlx,
										info->parse.res.x, info->parse.res.y);
	if (info->img.one.img == 0)
		error_destroy(info, "mlx_new_image failed");
	info->img.one.addr = mlx_get_data_addr(info->img.one.img,
				&info->img.one.bits_per_pixel, &info->img.one.line_length,
														&info->img.one.endian);
	if (info->img.one.addr == 0)
		error_destroy(info, "mlx_get_data_addr failed");
	ft_start(info);
	ft_bzero(&bmpimage, sizeof(t_bmpimage));
	bmpimage.padding = (4 - ((info->parse.res.x * 3) % 4)) % 4;
	bmpimage.linesize = info->parse.res.x * 3 + bmpimage.padding;
	ft_make_header(info, &bmpimage.header, bmpimage.linesize);
	if (write(fd, &bmpimage.header, 54) == -1)
		error_destroy(info, "write failed");
	ft_write_color_bmp(info, fd, bmpimage.padding);
	mlx_destroy_image(info->mlx.mlx, info->img.one.img);
	close(fd);
}
