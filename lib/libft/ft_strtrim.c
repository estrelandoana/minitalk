/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:37:45 by apaula-l          #+#    #+#             */
/*   Updated: 2023/11/03 16:09:31 by apaula-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (s1 == NULL || set == NULL)
	{
		return (NULL);
	}
	while (ft_strchr(set, *s1) && *s1 != '\0')
	{
		s1++;
	}
	i = ft_strlen(s1);
	while (ft_strchr(set, s1[i - 1]) && i > 0)
	{
		i--;
	}
	return (ft_substr(s1, 0, i));
}
