/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vla_char1.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 12:44:22 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/18 13:17:54 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vla.h"
#include <stdio.h>

static void	ft_free_map_char(char **map, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static int	ft_vla_char_expand_map(t_vla_char *vla)
{
	int		i;
	char	**res;

	i = 0;
	vla->size_map *= 2;
	res = malloc(sizeof(char*) * (vla->size_map + 1));
	if (res == 0)
		return (-1);
	res[vla->size_map] = (char*)0;
	while (vla->map[i] != '\0')
	{
		res[i] = vla->map[i];
		i++;
	}
	free(vla->map);
	vla->map = res;
	return (0);
}

int			ft_vla_char_add_element(t_vla_char *vla, char *elem)
{
	int	ret;

	if (vla->current_elem == vla->size_map)
	{
		ret = ft_vla_char_expand_map(vla);
		if (ret == -1)
		{
			free(vla->map);
			return (-1);
		}
	}
	vla->map[vla->current_elem] = elem;
	vla->current_elem++;
	return (0);
}

int			ft_vla_char_resize(t_vla_char *vla)
{
	int		i;
	char	**res;

	i = 0;
	res = malloc(sizeof(char*) * (vla->current_elem + 1));
	if (!res)
		return (-1);
	res[vla->current_elem] = NULL;
	while (i < vla->current_elem)
	{
		res[i] = vla->map[i];
		i++;
	}
	free(vla->map);
	vla->map = res;
	vla->size_map = i;
	return (0);
}

int			ft_vla_char_init(t_vla_char *vla, int size_map)
{
	vla->current_elem = 0;
	if (size_map >= 1)
		vla->size_map = size_map;
	else
		vla->size_map = 1;
	vla->map = malloc(sizeof(char*) * (vla->size_map + 1));
	if (vla->map == 0)
		return (-1);
	vla->map[vla->size_map] = (char*)0;
	return (0);
}
