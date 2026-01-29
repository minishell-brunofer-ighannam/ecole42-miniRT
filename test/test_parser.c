/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:52:29 by ighannam          #+#    #+#             */
/*   Updated: 2026/01/29 19:05:24 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "scene.h"

int main(int argc, char **argv)
{
    (void)argc;
    t_scene *scene;

    scene = ft_parser(argv[1]);
    ft_print_scene(scene);
    return (0);
}