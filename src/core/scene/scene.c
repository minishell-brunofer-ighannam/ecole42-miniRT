/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:23:18 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/25 17:27:05 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "scene.h"
#include "scene_internal.h"

void	ft_destroy_scene(t_scene *scene, void *mlx_ptr)
{
	int	i;

	if (!scene)
		return ;
	i = -1;
	while (++i < scene->num_polyhedron)
	{
		if (scene->polyhedron[i].material.has_texture_color)
			mlx_destroy_image(mlx_ptr,
				scene->polyhedron[i].material.texture_color.img_texture);
		if (scene->polyhedron[i].material.has_texture_normal)
			mlx_destroy_image(mlx_ptr,
				scene->polyhedron[i].material.texture_normal.img_texture);
		if (scene->polyhedron[i].material.pattern.pattern == CHECKER)
			free(scene->polyhedron[i].material.pattern.specs);
		free(scene->polyhedron[i].specs);
	}
	if (scene->polyhedron)
		free(scene->polyhedron);
	if (scene->light)
		free(scene->light);
	if (scene)
		free(scene);
}
