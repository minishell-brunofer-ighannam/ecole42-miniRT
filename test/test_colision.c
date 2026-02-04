/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_colision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:12:18 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/03 15:13:03 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "scene.h"
#include "ray_tracer.h"
#include "math_rt.h"
#include "colision.h"

void test_cylinder_body(void);
void test_sphere_front(void);
void test_plane_front(void);


void run_test(const char *name, bool condition)
{
    if (condition)
        printf("✅ %s\n", name);
    else
        printf("❌ %s\n", name);
}


void test_sphere_front(void)
{
    t_scene     *scene;
    t_ray       ray;
    t_colision  col;
    t_point_3d  expected;

    scene = ft_parser("scene/basic/0_test_sp.rt");

    ray.point = ft_new_point(0, 0, 0);
    ray.vector = ft_vector_normalize(ft_new_vector_3d(0, 0, 1));

    col = ft_closest_colision(scene, ray);

    run_test("sphere: collision exists", col.colision);

    expected = ft_new_point(0, 0, 4);
    run_test("sphere: hit point",
        ft_point_is_equal(col.colision_point, expected, EPS));

    scene->destroy(scene);
}


void test_plane_front(void)
{
    t_scene     *scene;
    t_ray       ray;
    t_colision  col;
    t_point_3d  expected;

    scene = ft_parser("scene/basic/0_test_pl.rt");

    ray.point = ft_new_point(0, 0, 0);
    ray.vector = ft_vector_normalize(ft_new_vector_3d(0, 0, 1));

    col = ft_closest_colision(scene, ray);

    run_test("plane: collision exists", col.colision);

    expected = ft_new_point(0, 0, 5);
    run_test("plane: hit point",
        ft_point_is_equal(col.colision_point, expected, EPS));

    scene->destroy(scene);
}


void test_cylinder_body(void)
{
    t_scene     *scene;
    t_ray       ray;
    t_colision  col;
    t_point_3d  expected;

    scene = ft_parser("scene/basic/0_test_cy.rt");

    ray.point = ft_new_point(1, 2, 0);
    ray.vector = ft_vector_normalize(ft_new_vector_3d(0, 0, 1));

    col = ft_closest_colision(scene, ray);

    run_test("cylinder body: collision exists", col.colision);

    expected = ft_new_point(1, 2, 5);
    run_test("cylinder body: hit point",
        ft_point_is_equal(col.colision_point, expected, EPS));

    scene->destroy(scene);
}

void test_closest_two_spheres(void)
{
    t_scene     *scene;
    t_ray       ray;
    t_colision  col;
    t_point_3d  expected;

    scene = ft_parser("scene/basic/0_test_2sp.rt");

    ray.point = ft_new_point(0, 0, 0);
    ray.vector = ft_vector_normalize(ft_new_vector_3d(0, 0, 1));

    col = ft_closest_colision(scene, ray);

    run_test("closest hit: collision exists", col.colision);

    expected = ft_new_point(0, 0, 3.5);
    run_test("closest hit: nearest sphere chosen",
        ft_point_is_equal(col.colision_point, expected, EPS));

    scene->destroy(scene);
}

void test_closest_sphere_vs_plane(void)
{
    t_scene     *scene;
    t_ray       ray;
    t_colision  col;
    t_point_3d  expected;

    scene = ft_parser("scene/basic/0_test_sp_pl.rt");

    ray.point = ft_new_point(0, 0, 0);
    ray.vector = ft_vector_normalize(ft_new_vector_3d(0, 0, 1));

    col = ft_closest_colision(scene, ray);

    run_test("closest hit (sphere vs plane): collision exists",
        col.colision);

    expected = ft_new_point(0, 0, 3.5);
    run_test("closest hit (sphere vs plane): sphere chosen",
        ft_point_is_equal(col.colision_point, expected, EPS));

    scene->destroy(scene);
}

void test_closest_sphere_vs_cylinder(void)
{
    t_scene     *scene;
    t_ray       ray;
    t_colision  col;
    t_point_3d  expected;

    scene = ft_parser("scene/basic/0_test_cy_sp.rt");

    ray.point = ft_new_point(0, 2, 0);
    ray.vector = ft_vector_normalize(ft_new_vector_3d(0, 0, 1));

    col = ft_closest_colision(scene, ray);

    run_test("closest hit (sphere vs cylinder): collision exists",
        col.colision);

    expected = ft_new_point(0, 2, 5.5);
    run_test("closest hit (sphere vs cylinder): sphere chosen",
        ft_point_is_equal(col.colision_point, expected, EPS));

    scene->destroy(scene);
}

int main(int argc, char **argv)
{
    if (argc < 1)
    {
        printf("usage: %s scene.rt\n", argv[0]);
        return (1);
    }
    test_sphere_front();
    test_plane_front();
    test_cylinder_body();
    
    test_closest_two_spheres();
    test_closest_sphere_vs_plane();
    test_closest_sphere_vs_cylinder();
    
    return (0);
}
