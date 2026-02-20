/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:26:02 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/20 13:44:48 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error\n ");
		return (1);
	}
	printf("[MANDADTORY] --> argv: %s\n", argv[1]);
}
