/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/19 13:36:15 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/19 13:48:41 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;
	size_t	i;

	i = 0;
	a = (void *)malloc(count * size);
	if (!a)
		return (0);
	while (i < count * size)
	{
		((char *)a)[i] = '\0';
		i++;
	}
	return (a);
}

void ft_pint_number(int *number)
{
	printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", number[0], number[1], number[2], number[3], number[4], number[5], number[6], number[7]);
}

int	main(void)
{
	int *number;

	number[0] = 4;
	number[1] = 2000;
	number[2] = 1;
	number[3] = 2;
	number[4] = 3;
	number[5] = 4;
	number[6] = 5;
	number[7] = 6;
	ft_pint_number(number);
	return (0);
}
