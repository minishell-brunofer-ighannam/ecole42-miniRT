/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_state_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:18:07 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/15 15:39:06 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_STATE_BONUS_H
# define CAMERA_STATE_BONUS_H

# include <stdio.h>
# include "libft.h"
# include "minilibx.h"

typedef struct s_set_movement	t_set_movement;

t_set_movement	ft_new_camera_translation(void);
t_set_movement	ft_new_camera_rotation(void);

#endif
