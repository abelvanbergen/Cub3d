/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 09:18:19 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/26 18:24:20 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	int		*buf;
	size_t	i;

	buf = (int*)b;
	i = 0;
	while (i < len)
	{
		buf[i] = c;
		i++;
	}
	return (b);
}
