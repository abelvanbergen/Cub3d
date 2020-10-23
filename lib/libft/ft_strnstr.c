/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 13:08:11 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/26 18:24:07 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (haystack[i] == '\0')
		return (0);
	while (haystack[i] != '\0' && i < len)
	{
		if (needle[j] == '\0')
			return ((char*)&haystack[i - j]);
		else if (haystack[i] == needle[j])
			j++;
		else
			j = 0;
		i++;
	}
	if (needle[j] == '\0')
		return ((char*)&haystack[i - j]);
	else
		return (0);
}
