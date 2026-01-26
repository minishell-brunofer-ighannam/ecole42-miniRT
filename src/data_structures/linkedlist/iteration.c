/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 01:40:17 by valero            #+#    #+#             */
/*   Updated: 2026/01/25 18:05:23 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"
#include "linkedlist_internal.h"

void	**ft_linkedlist_to_array(
			t_linkedlist *self,
			void *(*dup_content)(void *content),
			void (*free_content)(void *content))
{
	void				**result;
	t_linkedlist_node	*curr_node;
	int					idx;

	result = ft_calloc(self->size + 1, sizeof(self->first->content));
	if (!result)
		return (NULL);
	curr_node = self->first;
	idx = 0;
	while (curr_node)
	{
		result[idx] = dup_content(curr_node->content);
		if (!result[idx])
		{
			while (--idx >= 0)
				free_content(&result[idx]);
			free(result);
			return (NULL);
		}
		curr_node = curr_node->next;
		idx++;
	}
	return (result);
}

void	ft_iteri_linkedlist(t_linkedlist *self, void (*ft_iteri)(void *arg))
{
	t_linkedlist_node	*node;

	if (!self)
		return ;
	node = self->first;
	while (node)
	{
		ft_iteri(node);
		node = node->next;
	}
}
