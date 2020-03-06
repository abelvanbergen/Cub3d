/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 09:04:55 by avan-ber       #+#    #+#                */
/*   Updated: 2020/03/05 18:32:30 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> //

static void	free_data(char **data)
{
	int j;

	j = 0;
	while (data[j] != '\0')
	{
		free(data[j]);
		j++;
	}
	free(data);
}

static char	*strfiller(char const *s, char c, int i)
{
	int		word_len;
	char	*str;

	word_len = 0;
	if (s[i] == c)
		i++;
	while (s[i + word_len] != c && s[i + word_len] != '\0')
		word_len++;
	str = (char*)malloc(word_len + 1);
	if (str == 0)
		return (0);
	word_len = 0;
	while (s[i + word_len] != c && s[i + word_len] != '\0')
	{
		str[word_len] = s[i + word_len];
		word_len++;
	}
	str[word_len] = '\0';
	return (str);
}

static int	word_count(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	printf("%d\n", count);
	return (count);
}

static int	datafiller(char **data, char const *s, char c, int word_c)
{
	int i;
	int	word_amount;

	i = 0;
	word_amount = 0;
	while (word_amount < word_c)
	{
		if ((s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
				|| (i == 0 && s[i] != c))
		{
			data[word_amount] = strfiller(s, c, i);
			if (data[word_amount] == 0)
			{
				free_data(data);
				return (0);
			}
			word_amount++;
		}
		i++;
	}
	return (1);
}

char		**ft_split(char const *s, char c)
{
	int		word_c;
	char	**data;
	int		check;

	if (s == 0)
		return (0);
	word_c = word_count(s, c);
	data = (char**)malloc(sizeof(char*) * (word_c + 1));
	if (data == 0)
		return (0);
	data[word_c] = (char*)0;
	check = datafiller(data, s, c, word_c);
	if (check == 0)
		return (0);
	else
		return (data);
}
