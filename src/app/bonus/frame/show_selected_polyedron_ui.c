/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_selected_polyedron_ui.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 23:07:06 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/19 00:31:19 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "includes/frame_internal.h"

static void	ft_draw_outside_block(t_state *state, t_mlx *mlx);

void	ft_sow_selected_polyedron_ui(t_context *context)
{
	t_parallel	*parallel;
	t_state		*state;


	parallel = context->parallel;
	state = &context->events.state;
	pthread_mutex_lock(&parallel->flow_ctrl->mutex_set_state);
	if (state->window.height > 300 && state->window.width > 300
		&& state->scene.polyhedron.selected)
	{
		ft_draw_outside_block(state, &context->mlx);
	}
	context->mlx.display_image(context->mlx);
	pthread_mutex_unlock(&parallel->flow_ctrl->mutex_set_state);
}

static void	ft_draw_outside_block(t_state *state, t_mlx *mlx)
{
	t_vector_3d	min;
	t_vector_3d	max;
	t_vector_3d	count;
	int			color;

	color = 0xffffffff;
	(void)state;
	ft_bzero(&min, sizeof(t_vector_3d));
	ft_bzero(&max, sizeof(t_vector_3d));
	ft_bzero(&count, sizeof(t_vector_3d));
	max.x = mlx->window.width - 5;
	min.x = max.x - 215;
	max.y = mlx->window.height - 5;
	min.y = max.y - 265;
	count.x = min.x - 1;
	while (++count.x <= max.x)
	{
		count.y = min.y -1;
		while (++count.y <= max.y)
		{
			*mlx->frame_buffer[(int)count.x][(int)count.y] = color;
		}
	}

}
