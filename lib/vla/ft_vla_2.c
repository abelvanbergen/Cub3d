/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vla_2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 16:17:15 by avan-ber       #+#    #+#                */
/*   Updated: 2020/03/06 12:19:17 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vla.h"

void		ft_vla_init(t_vla *vla, int size_array, int size_elem)
{
	if (size_array < 1)
		vla->size_array = 1;
	else
		vla->size_array = size_array;
	vla->size_elem = size_elem;
	vla->cur_elem = 0;
	vla->array = malloc(vla->size_array * vla->size_elem);
}
