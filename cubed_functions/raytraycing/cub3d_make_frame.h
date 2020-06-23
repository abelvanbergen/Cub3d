/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_make_frame.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 13:58:54 by avan-ber      #+#    #+#                 */
/*   Updated: 2020/06/23 17:00:38 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MAKE_FRAME_H
# define CUB3D_MAKE_FRAME_H
# include "cub3d.h"

/*
** Cub3d make frame ------------------------------------------------------------
*/

/*
** Cub3d make frame utils
*/

t_2int	ft_get_pos_map(t_2doub pos);
void	ft_set_ray_dir(t_info *info);
t_2doub	ft_set_start_deltadistance(t_2doub ray_dir);
void	ft_set_step_and_sidedistance(t_ray *ray, t_2int map);
void	ft_digital_differential_analysis(t_ray *ray);

void	ft_set_perpendicular_wall_distance(t_ray *ray, int coor_x);
void	ft_set_line(t_ray *ray, int h);

/*
**==============================================================================
*/

#endif
