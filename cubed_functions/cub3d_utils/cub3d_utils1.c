/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_utils1.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 11:14:04 by avan-ber       #+#    #+#                */
/*   Updated: 2020/03/05 13:08:43 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_message1(char *message, int exitvalue)
{
	write(1, "error\n", 6);
	ft_putendl_fd(message, 1);
	exit(exitvalue);
}

void	error_message2(char *message1, char *message2, int exitvalue)
{
	write(1, "error\n", 6);
	write(1, message1, ft_strlen(message1));
	ft_putendl_fd(message2, 1);
	exit(exitvalue);
}

void	error_message3(char *message1, char *message2, char *message3,
																int exitvalue)
{
	write(1, "error\n", 6);
	write(1, message1, ft_strlen(message1));
	write(1, message2, ft_strlen(message2));
	ft_putendl_fd(message3, 1);
	exit(exitvalue);
}

int	ft_arraylen(char **data)
{
	int i;

	i = 0;
	while (data[i] != '\0')
		i++;
	return (i);
}
