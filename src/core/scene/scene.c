/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:23:18 by ighannam          #+#    #+#             */
/*   Updated: 2026/01/30 10:58:17 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/scene.h"

void	ft_print_scene(t_scene *scene)
{
    int i;

    if (!scene)
    {
        printf("No scene found\n");
        return ;
    }
    
	printf("CAMERA\n");
	printf("position: %f, %f, %f\n", scene->camera.position.x,
		scene->camera.position.y, scene->camera.position.z);
	printf("3D normal vector: %f, %f, %f\n", scene->camera.orientation.x,
		scene->camera.orientation.y, scene->camera.orientation.z);
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
            printf("color: %f, %f, %f\n", ((t_sphere *)scene->polyhedron[i].specs)->material.albedo.x, ((t_sphere *)scene->polyhedron[i].specs)->material.albedo.y, ((t_sphere *)scene->polyhedron[i].specs)->material.albedo.z);
            printf("ka: %f\n", ((t_sphere *)scene->polyhedron[i].specs)->material.ka);
            printf("kd: %f\n", ((t_sphere *)scene->polyhedron[i].specs)->material.kd);
            printf("ks: %f\n", ((t_sphere *)scene->polyhedron[i].specs)->material.ks);
            printf("n: %f\n", ((t_sphere *)scene->polyhedron[i].specs)->material.n);
            printf("kr: %f\n", ((t_sphere *)scene->polyhedron[i].specs)->material.kr);
        }
        else if (scene->polyhedron[i].type == CYLINDER)
        {
            printf("Cylinder\n");
            printf("center: %f, %f, %f\n", ((t_cylinder *)scene->polyhedron[i].specs)->center.x, ((t_cylinder *)scene->polyhedron[i].specs)->center.y, ((t_cylinder *)scene->polyhedron[i].specs)->center.z);
            printf("vector orientation: %f, %f, %f\n", ((t_cylinder *)scene->polyhedron[i].specs)->orientation.x, ((t_cylinder *)scene->polyhedron[i].specs)->orientation.y, ((t_cylinder *)scene->polyhedron[i].specs)->orientation.z);
            printf("radius: %f\n",((t_cylinder *)scene->polyhedron[i].specs)->radius);
            printf("height: %f\n",((t_cylinder *)scene->polyhedron[i].specs)->height);
            printf("color: %f, %f, %f\n", ((t_cylinder *)scene->polyhedron[i].specs)->material.albedo.x, ((t_cylinder *)scene->polyhedron[i].specs)->material.albedo.y, ((t_cylinder *)scene->polyhedron[i].specs)->material.albedo.z);
            printf("ka: %f\n", ((t_cylinder *)scene->polyhedron[i].specs)->material.ka);
            printf("kd: %f\n", ((t_cylinder *)scene->polyhedron[i].specs)->material.kd);
            printf("ks: %f\n", ((t_cylinder *)scene->polyhedron[i].specs)->material.ks);
            printf("n: %f\n", ((t_cylinder *)scene->polyhedron[i].specs)->material.n);
            printf("kr: %f\n", ((t_cylinder *)scene->polyhedron[i].specs)->material.kr);
        }
        else if (scene->polyhedron[i].type == PLANE)
        {
            printf("Plane\n");
            printf("coords: %f, %f, %f\n", ((t_plane *)scene->polyhedron[i].specs)->point.x, ((t_plane *)scene->polyhedron[i].specs)->point.y, ((t_plane *)scene->polyhedron[i].specs)->point.z);
            printf("vector orientation: %f, %f, %f\n", ((t_plane *)scene->polyhedron[i].specs)->orientation.x, ((t_plane *)scene->polyhedron[i].specs)->orientation.y, ((t_plane *)scene->polyhedron[i].specs)->orientation.z);
            printf("color: %f, %f, %f\n", ((t_plane *)scene->polyhedron[i].specs)->material.albedo.x, ((t_plane *)scene->polyhedron[i].specs)->material.albedo.y, ((t_plane *)scene->polyhedron[i].specs)->material.albedo.z);
            printf("ka: %f\n", ((t_plane *)scene->polyhedron[i].specs)->material.ka);
            printf("kd: %f\n", ((t_plane *)scene->polyhedron[i].specs)->material.kd);
            printf("ks: %f\n", ((t_plane *)scene->polyhedron[i].specs)->material.ks);
            printf("n: %f\n", ((t_plane *)scene->polyhedron[i].specs)->material.n);
            printf("kr: %f\n", ((t_plane *)scene->polyhedron[i].specs)->material.kr);
        }
        i++;        
    }
    printf("\n");    
}
