/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_polyhedron_select.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 10:59:44 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/15 21:38:33 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polyhedron.h"
#include "colision.h"
#include "threads_bonus.h"
#include "gestures_bonus.h"
#include "includes/state_polyhedron_internal_bonus.h"

static void	ft_set_cone_state_components(
				t_polyhedron_state_component **components, int *n_components);
static void	ft_set_cylinder_state_components(
				t_polyhedron_state_component **components, int *n_components);
static void	ft_set_sphere_state_components(
				t_polyhedron_state_component **components, int *n_components);

void	ft_select_polyhedron(t_state *self, t_context *context, int x, int y)
{
	t_polyhedron_state				*state_poly;
	t_colision						col;
	t_scene							*scene;
	t_polyhedron_state_component	**comps;
	int								*n_comps;

	if (!self || !context)
		return (NULL);
	scene = &context->scene;
	col = ft_trace_ray(scene, &context->mlx, x, y);
	comps = &state_poly->components;
	n_comps = &state_poly->n_components;
	if (!col.colision)
		return ;
	state_poly = &self->scene.polyhedron;
	pthread_mutex_lock(&self->parallel->flow_ctrl->mutex_set_state);
	state_poly->selected = ft_find_polyhedron(scene, col.polyhedron.id);
	if (state_poly->selected->type == CONE)
		ft_set_cone_state_components(comps, n_comps);
	else if (state_poly->selected->type == CYLINDER)
		ft_set_cylinder_state_components(comps, n_comps);
	else
		ft_set_sphere_state_components(comps, n_comps);
	pthread_mutex_unlock(&self->parallel->flow_ctrl->mutex_set_state);
}

void	ft_unselect_polyhedron(t_state *self)
{
	int					i;
	t_polyhedron_state	*polyhedron;

	pthread_mutex_lock(&self->parallel->flow_ctrl->mutex_set_state);
	if (!self->scene.polyhedron.components)
	{
		pthread_mutex_unlock(&self->parallel->flow_ctrl->mutex_set_state);
		return ;
	}
	polyhedron = &self->scene.polyhedron;
	i = -1;
	while (++i < polyhedron->n_components)
		free(polyhedron->components[i].name);
	free(polyhedron->components);
	pthread_mutex_unlock(&self->parallel->flow_ctrl->mutex_set_state);
}

static void	ft_set_cone_state_components(
				t_polyhedron_state_component **components, int *n_components)
{
	*n_components = 3;
	(*components) = ft_calloc(*n_components,
			sizeof(t_polyhedron_state_component));
	(*components)[0].name = ft_strdup("Vertex");
	(*components)[0].variation_size = 1.0;
	(*components)[1].name = ft_strdup("Apex Angle");
	(*components)[1].variation_size = 1.0;
	(*components)[2].name = ft_strdup("Height");
	(*components)[2].variation_size = 1.0;
}

static void	ft_set_cylinder_state_components(
				t_polyhedron_state_component **components, int *n_components)
{
	*n_components = 2;
	(*components) = ft_calloc(*n_components,
			sizeof(t_polyhedron_state_component));
	(*components)[0].name = ft_strdup("Radius");
	(*components)[0].variation_size = 1.0;
	(*components)[1].name = ft_strdup("Height");
	(*components)[1].variation_size = 1.0;
}

static void	ft_set_sphere_state_components(
				t_polyhedron_state_component **components, int *n_components)
{
	*n_components = 1;
	(*components) = ft_calloc(*n_components,
			sizeof(t_polyhedron_state_component));
	(*components)[0].name = ft_strdup("Radius");
	(*components)[0].variation_size = 1.0;
}
