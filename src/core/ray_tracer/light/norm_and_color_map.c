/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_and_color_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:00:47 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/18 17:45:15 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "light_internal.h"

t_vector_3d	ft_norm_albedo_map(t_colision *col, int x, int y)
{
	unsigned char	*pixel;

	x = col->u_norm * (col->polyhedron.material.texture_color.w - 1);
	y = col->v_norm * (col->polyhedron.material.texture_color.h - 1);
	pixel = col->polyhedron.material.texture_color.data + (y
			* col->polyhedron.material.texture_color.line_len + x
			* (col->polyhedron.material.texture_color.bpp / 8));
	return (ft_new_vector_3d(pixel[2] / 255.0, pixel[1] / 255.0, pixel[0]
			/ 255.0));
}

void	ft_update_normal(t_colision *col, int x, int y, t_vector_3d normal)
{
	unsigned char	*pixel;
	t_vector_3d		nm;
	t_vector_3d		b;
	t_vector_3d		world_nm;
	t_vector_3d		t;

	x = col->u_norm * (col->polyhedron.material.texture_normal.w - 1);
	y = col->v_norm * (col->polyhedron.material.texture_normal.h - 1);
	pixel = col->polyhedron.material.texture_normal.data + (y
			* col->polyhedron.material.texture_normal.line_len + x
			* (col->polyhedron.material.texture_normal.bpp / 8));
	nm = ft_new_vector_3d(((pixel[0] / 255.0) * 2.0 - 1), -((pixel[1] / 255.0)
				* 2.0 - 1), ((pixel[2] / 255.0) * 2.0 - 1));
	t = col->dir_u;
	b = col->dir_v;
	world_nm = ft_vec_norm(ft_vec_add(ft_vec_add(ft_vec_mult(t, nm.x),
					ft_vec_mult(b, nm.y)), ft_vec_mult(normal, nm.z)));
	col->normal = world_nm;
}
