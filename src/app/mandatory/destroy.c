/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 16:27:26 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/25 16:31:46 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "mandatory.h"

void	ft_destroy_app(t_context *context)
{
	t_mlx	*mlx;
	t_scene	*scene;

	mlx = &context->mlx;
	scene = context->scene;
	mlx->destroy(*mlx);
	if (scene)
		scene->destroy(scene);
}
