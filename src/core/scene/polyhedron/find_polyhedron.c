/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_polyhedron.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:03:50 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/15 16:12:25 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polyhedron_internal.h"

t_polyhedron	*ft_find_polyhedron(t_scene *scene, int id)
{
	t_polyhedron	*polyhedrons;
	int				start;
	int				end;

	polyhedrons = scene->polyhedron;
	start = -1;
	end = scene->num_polyhedron;
	while (++start <= --end)
	{
		if (polyhedrons[start].id == id)
			return (&polyhedrons[start]);
		if (polyhedrons[end].id == id)
			return (&polyhedrons[end]);
	}
	return (NULL);
}
