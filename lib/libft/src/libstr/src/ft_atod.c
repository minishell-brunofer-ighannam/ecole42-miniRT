/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:05:15 by ighannam          #+#    #+#             */
/*   Updated: 2026/01/29 19:01:29 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

static int		ft_strlen_int(char *str);
static double	ft_str_int(char *str);
static double	ft_str_dec(char *str);
static int	ft_str_exp(char *str);

double	ft_atod(char *str)
{
	int		sign;
	double	result;
	int		exp;

	sign = 1;
	while ((*str) == ' ')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	result = sign * (ft_str_int(str) + ft_str_dec(str));
	exp = ft_str_exp(str);
	result = sign * result * pow(10.0, exp);
	return (result);
}

static int	ft_strlen_int(char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\0' && str[size] != '.')
		size++;
	return (size);
}

static double	ft_str_int(char *str)
{
	int		size;
	double	result;
	int		pos;

	size = ft_strlen_int(str);
	result = 0;
	pos = 0;
	while (pos < size)
	{
		result = result * 10 + (str[pos] - '0');
		pos++;
	}
	return (result);
}

static double	ft_str_dec(char *str)
{
	double	result;
	double	div;

	result = 0;
	div = 10;
	while (*str != '.' && *str != '\0')
		str++;
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result + ((*str) - '0') / div;
		str++;
		div = div * 10;
	}
	return (result);
}

static int	ft_str_exp(char *str)
{
	int	sign;
	int	exp;

	sign = 1;
	exp = 0;
	while (*str && *str != 'e' && *str != 'E')
		str++;
	if (*str == '\0')
		return (0);
	str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		exp = exp * 10 + (*str - '0');
		str++;
	}
	return (sign * exp);
}
