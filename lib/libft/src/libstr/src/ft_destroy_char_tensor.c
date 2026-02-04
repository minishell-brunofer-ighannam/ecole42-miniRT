/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_char_tensor.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:15:09 by ighannam          #+#    #+#             */
/*   Updated: 2026/01/28 11:16:16 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

void	*ft_destroy_char_tensor(char ****tensor_ref)
{
	int	i;

	if (!tensor_ref || !*tensor_ref)
		return (NULL);
	i = 0;
	while ((*tensor_ref)[i])
	{
		ft_destroy_char_matrix(&(*tensor_ref)[i]);
		i++;
	}
	free(*tensor_ref);
	*tensor_ref = NULL;
	return (NULL);
}
