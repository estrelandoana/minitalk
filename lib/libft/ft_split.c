/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:25:30 by apaula-l          #+#    #+#             */
/*   Updated: 2023/11/13 02:07:14 by apaula-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;

	i = 0;
	if (*s == '\0')
	{
		return (0);
	}
	while (*s != '\0')
	{
		while (*s == c)
		{
			s++;
		}
		if (*s != '\0')
		{
			i++;
		}
		while (*s != c && *s != '\0')
		{
			s++;
		}
	}	
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	len;
	int		i;

	words = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	i = 0;
	if (s == NULL || words == NULL)
		return (0);
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != '\0')
		{
			if (ft_strchr(s, c) == NULL)
				len = ft_strlen(s);
			else
				len = ft_strchr(s, c) - s;
			words[i++] = ft_substr(s, 0, len);
			s += len;
		}
	}
	words[i] = NULL;
	return (words);
}
