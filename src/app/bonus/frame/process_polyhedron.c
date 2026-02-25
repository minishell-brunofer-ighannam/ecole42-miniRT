/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_polyhedron.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 19:18:47 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/25 12:44:47 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "includes/frame_internal.h"

static inline void	ft_handle_material(t_material *mat_poly,
		t_polyhedron_state_material *mat_state)
{
	t_vector_3d	*albedo_poly;
	t_vector_3d	*albedo_state;

	mat_poly->ka = ft_add_clamp(mat_poly->ka, mat_state->ka, 0, 1);
	mat_poly->kd = ft_add_clamp(mat_poly->kd, mat_state->kd, 0, 1);
	mat_poly->kr = ft_add_clamp(mat_poly->kr, mat_state->kr, 0, 1);
	mat_poly->ks = ft_add_clamp(mat_poly->ks, mat_state->ks, 0, 1);
	mat_poly->n = ft_add_clamp(mat_poly->n, mat_state->n, 0, 100);
	albedo_poly = &mat_poly->albedo;
	albedo_state = &mat_state->albedo;
	albedo_poly->x = ft_clamp(albedo_poly->x + albedo_state->x * 10, 0, 255);
	mat_poly->norm_albedo.x = albedo_poly->x / 255;
	albedo_poly->y = ft_clamp(albedo_poly->y + albedo_state->y * 10, 0, 255);
	mat_poly->norm_albedo.y = albedo_poly->y / 255;
	albedo_poly->z = ft_clamp(albedo_poly->z + albedo_state->z * 10, 0, 255);
	mat_poly->norm_albedo.z = albedo_poly->z / 255;
}

static inline void	ft_handle_1component_polyhdron(
						t_polyhedron_state *state_polyhedron,
						t_polyhedron *polyhedron)
{
	t_sphere	*sphere;
	t_cylinder	*cylinder;
	t_cone		*cone;

	sphere = polyhedron->specs;
	cylinder = polyhedron->specs;
	cone = polyhedron->specs;
	if (polyhedron->type == SPHERE)
		sphere->radius = ft_add_clamp(sphere->radius,
				state_polyhedron->components[0].value, 0.1, 200);
	else if (polyhedron->type == CYLINDER)
		cylinder->radius += state_polyhedron->components[0].value;
	else if (polyhedron->type == CONE)
		cone->half_apex_angle = ft_add_clamp(cone->half_apex_angle,
				state_polyhedron->components[0].value, 1, 70);
	state_polyhedron->components[0].value = 0;
}

static inline void	ft_handle_components(t_polyhedron_state *state_polyhedron,
		t_polyhedron *polyhedron)
{
	t_cylinder	*cylinder;
	t_cone		*cone;

	cylinder = polyhedron->specs;
	cone = polyhedron->specs;
	if (state_polyhedron->n_components)
		ft_handle_1component_polyhdron(state_polyhedron, polyhedron);
	if (state_polyhedron->n_components > 1)
	{
		if (polyhedron->type == CYLINDER)
			cylinder->height += state_polyhedron->components[1].value;
		else if (polyhedron->type == CONE)
			cone->height += state_polyhedron->components[1].value;
		state_polyhedron->components[1].value = 0;
	}
	if (polyhedron->type == CONE)
		ft_cone_recalculate(cone);
}

void	ft_handle_polyhedron(t_polyhedron_state *state_polyhedron)
{
	t_polyhedron					*polyhedron;
	int								n_components;
	t_polyhedron_state_component	*components;

	if (!state_polyhedron)
		return ;
	components = state_polyhedron->components;
	n_components = state_polyhedron->n_components;
	polyhedron = state_polyhedron->selected;
	if (polyhedron)
	{
		ft_handle_material(&polyhedron->material, &state_polyhedron->material);
		ft_handle_components(state_polyhedron, polyhedron);
	}
	ft_bzero(state_polyhedron, sizeof(t_polyhedron_state));
	state_polyhedron->selected = polyhedron;
	state_polyhedron->n_components = n_components;
	state_polyhedron->components = components;
}
