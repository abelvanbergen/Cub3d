/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 14:09:07 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/26 18:24:05 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*str;

	i = 0;
	s_len = 0;
	if (s == 0)
		return (0);
	while (s[s_len] != '\0')
		s_len++;
	if (start > s_len)
		return (ft_strdup(""));
	if (start + len <= s_len)
		str = (char *)malloc(len + 1);
	else
		str = (char *)malloc(s_len - start + 1);
	if (str == 0)
		return (0);
	while (i < len && s[start + i] != '\0')
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
