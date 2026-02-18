/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:23:18 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/18 17:48:08 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "scene_internal.h"

void	ft_destroy_scene(t_scene *scene)
{
	int	i;

	if (!scene)
		return ;
	i = 0;
	while (i < scene->num_polyhedron)
	{
		free(scene->polyhedron[i].specs);
		i++;
	}
	if (scene->polyhedron)
		free(scene->polyhedron);
	if (scene->light)
		free(scene->light);
	if (scene)
		free(scene);
}
