/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:49:18 by brunofer          #+#    #+#             */
/*   Updated: 2026/01/30 16:50:29 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

static int		ft_count_words(char const *s, char c);
static void		*ft_free_splited(char **splited, int j);

static void	*ft_free_splited(char **splited, int j)
{
	while (j > 0)
	{
		free(splited[j - 1]);
		j--;
	}
	free(splited);
	return (NULL);
}

static int	ft_count_words(char const *s, char c)
{
	int	num_words;

	num_words = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			if (*(s + 1) == c || *(s + 1) == '\0')
				num_words++;
		}
		s++;
	}
	return (num_words);
}

char	**ft_split(char const *s, char c)
{
	char	**splited;
	size_t	str_size;
	int		j;
	int		num_word;

	j = 0;
	num_word = ft_count_words(s, c);
	splited = malloc((num_word + 1) * sizeof(char *));
	if (!splited)
		return (NULL);
	while (*s != '\0' && j < num_word)
	{
		str_size = 0;
		while (*s == c && *s != '\0')
			s++;
		while (s[str_size] != c && s[str_size] != '\0')
			str_size++;
		s = s + str_size;
		splited[j] = malloc(str_size + 1);
		if (!splited[j])
			return (ft_free_splited(splited, j));
		ft_strlcpy(splited[j++], (s - str_size), str_size + 1);
	}
	splited[j] = NULL;
	return (splited);
}
