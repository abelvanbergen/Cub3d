/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 12:30:45 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/26 18:24:16 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int nb, int fd)
{
	int		i;
	char	str[10];

	i = 0;
	if (nb < 0)
		write(fd, "-", 1);
	if (nb == 0)
		write(fd, "0", 1);
	while (nb != 0)
	{
		if (nb > 0)
			str[i] = '0' + nb % 10;
		else
			str[i] = '0' - (nb % 10);
		nb /= 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(fd, &str[i], 1);
		i--;
	}
}
