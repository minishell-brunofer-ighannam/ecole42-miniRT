/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:03:27 by ighannam          #+#    #+#             */
/*   Updated: 2026/01/29 09:02:03 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

static int	ft_count_zeros_left(char *str);

bool	ft_is_int(char *str)
{
	int		i;
	long	result;

	if (!str || str[0] == '\0' || (ft_strlen(str)
			- ft_count_zeros_left(str)) > 11)
		return (false);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (false);
	while (str[i])
	{
		if (!ft_isdigit((unsigned char)str[i]))
			return (false);
		i++;
	}
	result = ft_atol(str);
	if (result > INT_MAX || result < INT_MIN)
		return (false);
	return (true);
}

static int	ft_count_zeros_left(char *str)
{
	int	zeros;

	zeros = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '0')
		{
			zeros++;
			str++;
		}
		else
			break ;
	}
	return (zeros);
}
