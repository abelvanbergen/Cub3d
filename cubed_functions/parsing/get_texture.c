/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_texture.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 10:47:37 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/17 12:21:26 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_texture(void *mlx, char **texture, t_imginfo *loc)
{
	if (loc->set == 1)
		error_message2("This element already exist\nElemnt: ", texture[0], 1);
	if (ft_arraylen(texture) != 2)
		error_message2("Texture element does not have \
					the right amount of arguments\nTexture: ", texture[0], 1);
	loc->img = mlx_png_file_to_image(mlx, texture[1],
											&loc->img_width, &loc->img_height);
	if (loc->img == 0)
		error_message2("Path to texture is invalid\nTexture: ", texture[0], 1);
	loc->addr = mlx_get_data_addr(loc->img, &loc->bits_per_pixel, &loc->line_length, &loc->endian);
	loc->set = 1;
}
