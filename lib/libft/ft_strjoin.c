/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:27:48 by apaula-l          #+#    #+#             */
/*   Updated: 2023/11/03 15:05:31 by apaula-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*joint;
	size_t		len_s1;
	size_t		len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	joint = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (joint == NULL)
	{
		return (NULL);
	}
	ft_memcpy (joint, s1, len_s1);
	ft_memcpy (&joint[len_s1], s2, len_s2);
	joint[len_s1 + len_s2] = '\0';
	return (joint);
}
