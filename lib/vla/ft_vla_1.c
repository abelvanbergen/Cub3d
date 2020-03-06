/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vla_1.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 13:50:15 by avan-ber       #+#    #+#                */
/*   Updated: 2020/03/06 12:15:58 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vla.h"
#include <stddef.h>

static void	*ft_memcpy(void *dst, const void *src, size_t n)
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

int			vla_resize(t_vla *vla)
{
	void	*res_array;

	res_array = malloc((vla->cur_elem + 1) * vla->size_elem);
	if (res_array == 0)
		return (-1);
	ft_memcpy(res_array, vla->array, (vla->cur_elem + 1) * vla->size_elem);
	free(vla->array);
	vla->array = res_array;
	return (0);
}

int			vla_expand_array(t_vla *vla)
{
	void	*array2;

	vla->size_array *= 2;
	array2 = malloc(vla->size_array * vla->size_elem);
	if (array2 == 0)
		return (-1);
	ft_memcpy(array2, vla->array, vla->size_elem * (vla->cur_elem + 1));
	free(vla->array);
	vla->array = array2;
	return (0);
}

int			ft_vla_add_element(t_vla *vla, char *str)
{
	int ret;

	if (vla->size_array == vla->cur_elem)
	{
		ret = vla_expand_array(vla);
		if (ret == -1)
		{
			free(vla->array);
			return (-1);
		}
	}
	ft_memcpy(vla->array + vla->cur_elem * vla->size_elem,
														&str, vla->size_elem);
	vla->cur_elem++;
	return (0);
}

int			ft_vla_get_elem(t_vla vla, int place, void *result)
{
	if (place > vla.cur_elem)
		return (-1);
	ft_memcpy(result, vla.array + place * vla.size_elem, vla.size_elem);
	return (0);
}
