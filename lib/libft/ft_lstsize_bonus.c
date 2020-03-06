/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 11:16:28 by avan-ber       #+#    #+#                */
/*   Updated: 2019/11/11 11:24:01 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int c;

	c = 0;
	if (lst == 0)
		return (c);
	while (lst->next != '\0')
	{
		lst = lst->next;
		c++;
	}
	return (c + 1);
}
