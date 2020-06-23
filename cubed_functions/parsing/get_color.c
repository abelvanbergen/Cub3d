/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_color.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 16:57:52 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/23 17:30:06 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	ft_nondigit(char *str)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]) == 1)
		i++;
	return (i);
}

static int	ft_get_color(int color_nb, t_colorelem *loc, char *str)
{
	int ret;

	ret = ft_atoi(str);
	if (ret < 0 || ret > 255)
		return (-1);
	loc->trgb[color_nb] = (unsigned char)ret;
	return (ft_nondigit(str));
}

static void	ft_fill_union_color(t_colorelem *loc, char **data)
{
	int		i;
	int		ret;

	i = 0;
	ret = ft_get_color(red, loc, data[1]);
	if (ret == -1)
		error_message3("The color of a element does not have the right size\
		\nElement: ", data[0], "\nColor: red", 1);
	i += ret + 1;
	ret = ft_get_color(green, loc, &data[1][i]);
	if (ret == -1)
		error_message3("The color of a element does not have the right size\
		\nElement: ", data[0], "\nColor: green", 1);
	i += ret + 1;
	ret = ft_get_color(blue, loc, &data[1][i]);
	if (ret == -1)
		error_message3("The color of a element does not have the right size\
		\nElement: ", data[0], "\nColor: blue", 1);
}

static void	ft_check_layout_color(char **data)
{
	int i;

	i = ft_nondigit(data[1]);
	if (data[1][i] != ',')
		error_message2("The color element does not have the right layout\
		\nElement: 1", data[0], 1);
	i += ft_nondigit(&data[1][i + 1]) + 1;
	if (data[1][i] != ',')
		error_message2("The color element does not have the right layout\
		\nElement: 2", data[0], 1);
	i += ft_nondigit(&data[1][i + 1]) + 1;
	if (data[1][i] != '\0')
		error_message2("The color element does not have the right layout\
		\nElement: 3", data[0], 1);
}

void		get_color(char **data, t_colorelem *loc)
{
	if (loc->set == 1)
		error_message2("This element already exist\nElemnt: ", data[0], 1);
	if (ft_arraylen(data) != 2)
		error_message2("amount of arguments color invalid\nElement: ",
																	data[0], 1);
	ft_check_layout_color(data);
	ft_fill_union_color(loc, data);
	loc->set = 1;
}
