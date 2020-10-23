/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 16:50:31 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/26 17:31:49 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_check_inputfile(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (!(str[i - 1] == 'b' && str[i - 2] == 'u' && str[i - 3] == 'c' &&
															str[i - 4] == '.'))
	{
		error_message1("inputfile has the wrong name", 1);
	}
}

int			main(int ac, char **av)
{
	t_info	info;

	ft_bzero(&info, sizeof(t_info));
	if (ac == 2)
	{
		ft_check_inputfile(av[1]);
		info.mlx.mlx = mlx_init();
		if (!info.mlx.mlx)
			error_message1("mlx_init failed", 1);
		ft_parsefile(&info, av[1]);
		ft_cub3d_raytrace(info);
	}
	else if (ac == 3 && ft_strncmp("--save", av[2], 6) == 0)
	{
		ft_check_inputfile(av[1]);
		info.save = 1;
		info.mlx.mlx = mlx_init();
		if (!info.mlx.mlx)
			error_message1("mlx_init failed", 1);
		ft_parsefile(&info, av[1]);
		ft_make_screen_shot(&info);
	}
	else
		error_message1("the arguments are not right", 1);
	return (0);
}
