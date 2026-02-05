/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:23:18 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/05 17:56:41 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "scene_internal.h"

void	ft_print_scene(t_scene *scene)
{
    int i;

    if (!scene)
    {
        printf("No scene found\n");
        return ;
    }
    
	printf("CAMERA\n");
	printf("position: %f, %f, %f\n", scene->camera.origin.x,
		scene->camera.origin.y, scene->camera.origin.z);
	printf("3D normal vector: %f, %f, %f\n", scene->camera.forward.x,
		scene->camera.forward.y, scene->camera.forward.z);
	printf("FOV: %f\n\n", scene->camera.horizontal_fov);

    printf("AMBIENT\n");
    printf("intensity: %f\n", scene->ambient.intensity);
    printf("color: %f, %f, %f\n\n", scene->ambient.color.x, scene->ambient.color.y, scene->ambient.color.z);

    printf("LIGHTS\n");
    i = 0;
    while (i < scene->num_light)
    {
        printf("Light %d\n", i);
        printf("position: %f, %f, %f\n", scene->light[i].coord.x, scene->light[i].coord.y, scene->light[i].coord.z);
        printf("intensity: %f\n", scene->light[i].intensity);
        printf("color: %f, %f, %f\n", scene->light[i].color.x, scene->light[i].color.y, scene->light[i].color.z);
        printf("norm_color: %f, %f, %f\n", scene->light[i].norm_color.x, scene->light[i].norm_color.y, scene->light[i].norm_color.z);
        i++;
    }
    printf("\n");
    
    printf("POLYHEDRONS\n");
    i = 0;
    while (i < scene->num_polyhedron)
    {
        printf("\nPolyhedron %d\n", i);
        printf("type: %d\n", scene->polyhedron[i].type);
        if (scene->polyhedron[i].type == SPHERE)
        {
            printf("Sphere\n");
            printf("center: %f, %f, %f\n", ((t_sphere *)scene->polyhedron[i].specs)->center.x, ((t_sphere *)scene->polyhedron[i].specs)->center.y, ((t_sphere *)scene->polyhedron[i].specs)->center.z);
            printf("radius: %f\n",((t_sphere *)scene->polyhedron[i].specs)->radius);
            printf("color: %f, %f, %f\n", scene->polyhedron[i].material.albedo.x, scene->polyhedron[i].material.albedo.y, scene->polyhedron[i].material.albedo.z);
            printf("ka: %f\n", (scene->polyhedron[i].material.ka));
            printf("kd: %f\n", (scene->polyhedron[i].material.kd));
            printf("ks: %f\n", (scene->polyhedron[i].material.ks));
            printf("n: %f\n", (scene->polyhedron[i].material.n));
            printf("kr: %f\n", (scene->polyhedron[i].material.kr));
        }
        else if (scene->polyhedron[i].type == CYLINDER)
        {
            printf("Cylinder\n");
            printf("center: %f, %f, %f\n", ((t_cylinder *)scene->polyhedron[i].specs)->center.x, ((t_cylinder *)scene->polyhedron[i].specs)->center.y, ((t_cylinder *)scene->polyhedron[i].specs)->center.z);
            printf("vector axis: %f, %f, %f\n", ((t_cylinder *)scene->polyhedron[i].specs)->axis.x, ((t_cylinder *)scene->polyhedron[i].specs)->axis.y, ((t_cylinder *)scene->polyhedron[i].specs)->axis.z);
            printf("radius: %f\n",((t_cylinder *)scene->polyhedron[i].specs)->radius);
            printf("height: %f\n",((t_cylinder *)scene->polyhedron[i].specs)->height);
            printf("color: %f, %f, %f\n", scene->polyhedron[i].material.albedo.x, scene->polyhedron[i].material.albedo.y, scene->polyhedron[i].material.albedo.z);
            printf("ka: %f\n", (scene->polyhedron[i].material.ka));
            printf("kd: %f\n", (scene->polyhedron[i].material.kd));
            printf("ks: %f\n", (scene->polyhedron[i].material.ks));
            printf("n: %f\n", (scene->polyhedron[i].material.n));
            printf("kr: %f\n", (scene->polyhedron[i].material.kr));
        }
        else if (scene->polyhedron[i].type == PLANE)
        {
            printf("Plane\n");
            printf("coords: %f, %f, %f\n", ((t_plane *)scene->polyhedron[i].specs)->point.x, ((t_plane *)scene->polyhedron[i].specs)->point.y, ((t_plane *)scene->polyhedron[i].specs)->point.z);
            printf("vector normal: %f, %f, %f\n", ((t_plane *)scene->polyhedron[i].specs)->normal.x, ((t_plane *)scene->polyhedron[i].specs)->normal.y, ((t_plane *)scene->polyhedron[i].specs)->normal.z);
            printf("color: %f, %f, %f\n", scene->polyhedron[i].material.albedo.x, scene->polyhedron[i].material.albedo.y, scene->polyhedron[i].material.albedo.z);
            printf("ka: %f\n", (scene->polyhedron[i].material.ka));
            printf("kd: %f\n", (scene->polyhedron[i].material.kd));
            printf("ks: %f\n", (scene->polyhedron[i].material.ks));
            printf("n: %f\n", (scene->polyhedron[i].material.n));
            printf("kr: %f\n", (scene->polyhedron[i].material.kr));
        }
        i++;        
    }
    printf("\n"); 
}

void ft_destroy_scene(t_scene *scene)
{
    int i;

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
