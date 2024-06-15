/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:47:56 by apaula-l          #+#    #+#             */
/*   Updated: 2023/10/28 22:30:18 by apaula-l         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;
	size_t	destlen;

	destlen = 0;
	srclen = ft_strlen(src);
	while (dest[destlen] != '\0' && destlen < size)
	{
		destlen++;
	}
	i = 0;
	if (destlen < size)
	{
		while ((i + destlen) < (size - 1) && src[i] != '\0')
		{
			dest[i + destlen] = src[i];
			i++;
		}
		dest[i + destlen] = '\0';
	}
	return (destlen + srclen);
}
