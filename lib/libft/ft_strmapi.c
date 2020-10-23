/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 13:39:15 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/26 18:24:09 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i] != '\0')
		i++;
	str = (char *)malloc(i + 1);
	if (str == 0)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = (f)(i, (const char)s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
