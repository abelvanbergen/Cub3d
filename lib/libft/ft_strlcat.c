/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 15:44:27 by avan-ber       #+#    #+#                */
/*   Updated: 2019/11/11 09:20:56 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t j_l;
	size_t i_l;

	j = 0;
	j_l = 0;
	i_l = 0;
	while (dst[i_l] != '\0')
		i_l++;
	while (src[j_l] != '\0')
		j_l++;
	i = i_l;
	while (src[j] != '\0' && i + j + 1 < dstsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	if (dstsize == 0)
		return (j_l);
	else if (dstsize > i_l)
		return (i_l + j_l);
	else
		return (dstsize + j_l);
}
