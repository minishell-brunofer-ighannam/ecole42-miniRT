/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:03:07 by ighannam          #+#    #+#             */
/*   Updated: 2026/02/25 13:41:17 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

static int	consume_digits(char *s, int *i);
static int	skip_sign(char *s, int *i);

bool	ft_is_double(char *str)
{
	int	i;
	int	has_digit;

	i = 0;
	has_digit = 0;
	if (!str || str[0] == '\0')
		return (false);
	skip_sign(str, &i);
	has_digit = consume_digits(str, &i);
	if (str[i] == '.')
	{
		i++;
		if (consume_digits(str, &i))
			has_digit = 1;
	}
	if ((str[i] == 'e' || str[i] == 'E') && has_digit)
	{
		i++;
		skip_sign(str, &i);
		if (!consume_digits(str, &i))
			return (false);
	}
	if (str[i] != '\0' || !has_digit)
		return (false);
	return (true);
}

static int	consume_digits(char *s, int *i)
{
	int	has_digit;

	has_digit = 0;
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		has_digit = 1;
		(*i)++;
	}
	return (has_digit);
}

static int	skip_sign(char *s, int *i)
{
	if (s[*i] == '+' || s[*i] == '-')
		(*i)++;
	return (0);
}
