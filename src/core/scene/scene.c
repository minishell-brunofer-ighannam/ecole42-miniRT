/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:23:18 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/20 12:44:04 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "scene_internal.h"

void	ft_destroy_scene(t_scene *scene)
{
	int	i;

	if (!scene)
		return ;
	i = -1;
	while (++i < scene->num_polyhedron)
		free(scene->polyhedron[i].specs);
	if (scene->polyhedron)
		free(scene->polyhedron);
	if (scene->light)
		free(scene->light);
	if (scene->pattern)
		free(scene->pattern);
	if (scene)
		free(scene);
}
