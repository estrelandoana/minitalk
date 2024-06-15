/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 00:28:12 by apaula-l          #+#    #+#             */
/*   Updated: 2023/10/29 00:52:57 by apaula-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;

	alloc = malloc(nmemb * size);
	if (alloc == NULL)
	{
		return (NULL);
	}
	ft_bzero(alloc, size * nmemb);
	return (alloc);
}
