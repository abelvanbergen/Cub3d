/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 12:27:35 by avan-ber       #+#    #+#                */
/*   Updated: 2019/11/12 14:21:00 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*empty_str(void)
{
	char	*str;

	str = (char*)malloc(1);
	str[0] = '\0';
	return (str);
}

static int	chr_trimmed_end(char const *s1, char const *set)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	i--;
	while (set[j] != '\0')
	{
		if (s1[i] == set[j])
		{
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

static int	chr_trimmed_begin(char const *s1, char const *set)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (set[j] != '\0' && s1[i] != '\0')
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i_begin;
	int		i_end;
	int		j;
	char	*str;

	i_begin = 0;
	i_end = 0;
	j = 0;
	if (s1 == 0)
		return (0);
	i_begin = chr_trimmed_begin(s1, set);
	i_end = chr_trimmed_end(s1, set);
	if (i_begin > i_end)
		return (empty_str());
	str = (char*)malloc(i_end - i_begin + 2);
	if (str == 0)
		return (0);
	while (i_begin + j <= i_end)
	{
		str[j] = s1[i_begin + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
