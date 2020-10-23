/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_texture.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 10:47:37 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/26 17:35:05 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_texture(void *mlx, char *rot, char *line, t_imginfo *loc)
{
	if (loc->set == 1)
		error_message2("This element already exist\nElemnt: ", rot, 1);
	while (*line == ' ')
		line++;
	line += 2;
	while (*line == ' ')
		line++;
	loc->img = mlx_png_file_to_image(mlx, line,
											&loc->img_width, &loc->img_height);
	if (loc->img == 0)
		error_message2("Path to texture is invalid\nTexture: ", rot, 1);
	loc->addr = mlx_get_data_addr(loc->img, &loc->bits_per_pixel,
											&loc->line_length, &loc->endian);
	if (loc->addr == 0)
		error_message1("mlx_get_data_addr failed", 1);
	loc->set = 1;
}
