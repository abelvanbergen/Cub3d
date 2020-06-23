/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_map.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 16:47:23 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/23 16:48:37 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parse_file_map(t_info *info, int fd, t_vla_char *vla)
{
	int			begin_map;
	int			ret;
	char		*line;

	begin_map = 0;
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			error_message1("Get_next_line failed", 1);
		if (*line)
		{
			if (begin_map == 2)
				error_message1("There is a newline in your map", 1);
			begin_map = 1;
			ft_vla_char_add_element(vla, line);
		}
		else
		{
			free(line);
			begin_map = (begin_map == 1) ? 2 : begin_map;
		}
		if (ret == 0)
			break ;
	}
}
