/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 08:42:54 by avan-ber       #+#    #+#                */
/*   Updated: 2019/11/11 08:24:15 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;
	size_t	i;

	i = 0;
	a = (void *)malloc(count * size);
	if (!a)
		return (0);
	while (i < count * size)
	{
		((char *)a)[i] = '\0';
		i++;
	}
	return (a);
}
