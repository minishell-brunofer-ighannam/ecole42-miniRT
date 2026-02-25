/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_polyhedron_select.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 10:59:44 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/25 12:29:53 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colision.h"
#include "gestures_bonus.h"
#include "includes/state_polyhedron_internal_bonus.h"
#include "scene.h"
#include "polyhedron.h"
#include "threads_bonus.h"

static void	ft_cone_comps(
				t_polyhedron_state_component **components,
				int *n_components);
static void	ft_cylinder_comps(
				t_polyhedron_state_component **components,
				int *n_components);
static void	ft_sphere_comps(
				t_polyhedron_state_component **components,
				int *n_components);

void	ft_select_polyhedron(t_context *context, t_scene *scene, int x, int y)
{
	t_polyhedron_state				*state_poly;
	t_colision						col;

	if (!context || x < 0 || y < 0)
		return ;
	col = ft_trace_ray(context, x, y);
	if (!col.colision)
		return ;
	set_polyhedron_changed_flag(&context->events.state);
	state_poly = &context->events.state.scene.polyhedron;
	pthread_mutex_lock(
		&context->events.state.parallel->flow_ctrl->mutex_set_state);
	if (state_poly->selected)
		ft_unselect_polyhedron(context);
	state_poly->selected = ft_find_polyhedron(scene, col.polyhedron.id);
	if (state_poly->selected->type == CONE)
		ft_cone_comps(&state_poly->components, &state_poly->n_components);
	else if (state_poly->selected->type == CYLINDER)
		ft_cylinder_comps(&state_poly->components, &state_poly->n_components);
	else if (state_poly->selected->type == SPHERE)
		ft_sphere_comps(&state_poly->components, &state_poly->n_components);
	else
		state_poly->n_components = 0;
	pthread_mutex_unlock(
		&context->events.state.parallel->flow_ctrl->mutex_set_state);
}

void	ft_unselect_polyhedron(t_context *context)
{
	int					i;
	t_polyhedron_state	*polyhedron;
	t_state				*state;

	state = &context->events.state;
	if (!state->scene.polyhedron.selected)
	{
		pthread_mutex_unlock(&state->parallel->flow_ctrl->mutex_set_state);
		return ;
	}
	set_polyhedron_changed_flag(state);
	polyhedron = &state->scene.polyhedron;
	polyhedron->selected = NULL;
	i = -1;
	if (state->scene.polyhedron.components)
	{
		while (++i < polyhedron->n_components)
			free(polyhedron->components[i].name);
		free(polyhedron->components);
		polyhedron->components = NULL;
	}
}

static void	ft_cone_comps(
				t_polyhedron_state_component **components,
				int *n_components)
{
	*n_components = 2;
	(*components) = ft_calloc(*n_components,
			sizeof(t_polyhedron_state_component));
	(*components)[0].name = ft_strdup("Apex Angle");
	(*components)[0].variation_size = 0.5;
	(*components)[1].name = ft_strdup("Height");
	(*components)[1].variation_size = 1.0;
}

static void	ft_cylinder_comps(
				t_polyhedron_state_component **components,
				int *n_components)
{
	*n_components = 2;
	(*components) = ft_calloc(*n_components,
			sizeof(t_polyhedron_state_component));
	(*components)[0].name = ft_strdup("Radius");
	(*components)[0].variation_size = 1.0;
	(*components)[1].name = ft_strdup("Height");
	(*components)[1].variation_size = 1.0;
}

static void	ft_sphere_comps(
				t_polyhedron_state_component **components,
				int *n_components)
{
	*n_components = 1;
	(*components) = ft_calloc(*n_components,
			sizeof(t_polyhedron_state_component));
	(*components)[0].name = ft_strdup("Radius");
	(*components)[0].variation_size = 0.05;
}
