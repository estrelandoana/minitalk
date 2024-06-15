/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:50:04 by apaula-l          #+#    #+#             */
/*   Updated: 2023/11/04 17:00:42 by apaula-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (f)(unsigned int, char))
{
	size_t	len;
	char	*r;

	if (s == NULL)
	{
		return (NULL);
	}
	len = ft_strlen(s);
	r = malloc((len + 1) * sizeof(char));
	if (r == NULL)
	{
		return (NULL);
	}
	r[len] = '\0';
	while (len > 0)
	{
		r[len - 1] = f(len - 1, s[len -1]);
		len--;
	}
	return (r);
}
