/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 02:08:41 by apaula-l          #+#    #+#             */
/*   Updated: 2023/10/29 02:23:38 by apaula-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned int	strlen;
	char			*dest;

	strlen = ft_strlen(s) + 1;
	dest = malloc(strlen);
	if (dest == NULL)
	{
		return (NULL);
	}
	ft_memcpy(dest, s, strlen);
	return (dest);
}
