/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 14:38:55 by avan-ber       #+#    #+#                */
/*   Updated: 2019/11/12 16:04:36 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int i_pos;

	i = 0;
	i_pos = -1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i_pos = i;
		i++;
	}
	if (s[i] == c)
		return ((char*)&s[i]);
	if (i_pos == -1)
		return (0);
	return ((char*)&s[i_pos]);
}
