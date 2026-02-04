/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_char_matrix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:37:14 by valero            #+#    #+#             */
/*   Updated: 2026/01/30 12:21:26 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

void	*ft_destroy_char_matrix(char ***char_matrix_ref)
{
	int	i;

	if (!char_matrix_ref || !*char_matrix_ref)
		return (NULL);
	i = 0;
	while ((*char_matrix_ref)[i])
	{
		free((*char_matrix_ref)[i]);
		(*char_matrix_ref)[i] = NULL;
		i++;
	}
	free(*char_matrix_ref);
	*char_matrix_ref = NULL;
	return (NULL);
}
