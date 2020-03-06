/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vla.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 13:48:30 by avan-ber       #+#    #+#                */
/*   Updated: 2020/03/06 15:42:44 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VLA_H
# define VLA_H

# include <stdlib.h>

typedef struct	s_vla
{
	int			size_array;
	int			size_elem;
	int			cur_elem;
	void		*array;
}				t_vla;

typedef struct	s_vla_char
{
	char	**map;
	int		size_map;
	int		current_elem;
}				t_vla_char;

void			ft_vla_init(t_vla *vla, int size_array, int size_elem);
int				ft_vla_get_elem(t_vla vla, int place, void *result);
int				ft_vla_add_element(t_vla *vla, char *str);
int				vla_expand_array(t_vla *vla);
int				vla_resize(t_vla *vla);

int				ft_vla_char_add_element(t_vla_char *vla, char *elem);
int				ft_vla_char_resize(t_vla_char *vla);
int				ft_vla_char_init(t_vla_char *vla, int size_map);

#endif
