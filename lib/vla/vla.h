/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vla.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 13:48:30 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/30 16:13:03 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VLA_H
# define VLA_H

# include <stdlib.h>

typedef struct	s_vla_char
{
	char	**map;
	int		size_map;
	int		current_elem;
}				t_vla_char;

int				ft_vla_char_add_element(t_vla_char *vla, char *elem);
int				ft_vla_char_resize(t_vla_char *vla);
int				ft_vla_char_init(t_vla_char *vla, int size_map);

#endif
