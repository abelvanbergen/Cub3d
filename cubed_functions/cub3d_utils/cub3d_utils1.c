/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_utils1.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 11:14:04 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/23 16:57:25 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_message1(char *message, int exitvalue)
{
	write(1, "\033[0;31m---error---\033[0m\n", 23);
	ft_putendl_fd(message, 1);
	exit(exitvalue);
}

void	error_message2(char *message1, char *message2, int exitvalue)
{
	write(1, "\033[0;31merror\033[0m\n", 17);
	write(1, message1, ft_strlen(message1));
	ft_putendl_fd(message2, 1);
	exit(exitvalue);
}

void	error_message3(char *message1, char *message2, char *message3,
																int exitvalue)
{
	write(1, "\033[0;31merror\033[0m\n", 17);
	write(1, message1, ft_strlen(message1));
	write(1, message2, ft_strlen(message2));
	ft_putendl_fd(message3, 1);
	exit(exitvalue);
}

int		ft_arraylen(char **data)
{
	int i;

	i = 0;
	while (data[i] != '\0')
		i++;
	return (i);
}

void	my_mlx_pixel_put(t_imginfo *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
