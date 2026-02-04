/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_first_hit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:44:36 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/04 10:52:30 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "parser.h"
#include "scene.h"
#include "camera.h"
#include "ray_tracer.h"
#include "math_rt.h"
#include "colision.h"


void init_mlx(t_scene *scene)
{
    //ESSA FUNCAO É SÓ PARA TESTE
    void		*mlx;
    void	*win;
	void	*img;
    mlx = mlx_init();
    win = mlx_new_window(mlx, WIDTH, HEIGHT, "teste");
    img = mlx_new_image(mlx, WIDTH, HEIGHT);
    scene->mlx = mlx;
    scene->win = win;
	scene->img = img;
	scene->addr = mlx_get_minilib_layer_addr(img, &(scene->bpp), &(scene->line_len), &(scene->endian));
}

int main()
{
    t_scene     *scene;

    scene = ft_parser("scene/basic/2_spheres_red_blue.rt");
    ft_camera_init(&scene->camera);
    init_mlx(scene);
    ft_camera_ray_loop(scene);
    mlx_put_image_to_window(scene->mlx, scene->win, scene->img, 0, 0);
    mlx_loop(scene->mlx);
    return (0);
}