/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:22:44 by ighannam          #+#    #+#             */
/*   Updated: 2026/01/29 18:58:47 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_internal.h"

int	ft_count_size_splited(char **splited)
{
	int size;

	if (!splited)
		return (0);
	size = 0;
	while (splited[size])
		size++;
	return (size);
}

bool	ft_verify_double_between(char *str, double ref_one, double ref_two,
		double eps)
{
	double	eval;

	if (!str || !ft_is_double(str))
		return (false);
	eval = ft_atod(str);
	if (isinf(eval) || isnan(eval))
		return (false);
	if (ref_one != 0 || ref_two != 0)
		return (ft_is_between_double(ref_one, ref_two, eval, eps));
	return (true);
}

bool	ft_verify_int_between(char *str, int ref_one, int ref_two)
{
	if (!str || !ft_is_int(str))
		return (false);
	if (ref_one != 0 || ref_two != 0)
		return (ft_is_between_int(ref_one, ref_two, ft_atoi(str)));
	return (true);
}
