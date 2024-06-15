/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:27:33 by apaula-l          #+#    #+#             */
/*   Updated: 2023/11/11 23:23:09 by apaula-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_is_negative(long int n)
{
	if (n < 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

static size_t	ft_count_digits(long int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		return (1);
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int	neg;
	long int		num;
	unsigned int	dig;
	char			*r;

	num = n;
	neg = ft_is_negative(num);
	if (neg == 1)
		num *= -1;
	dig = ft_count_digits(num);
	r = (char *)malloc(dig + neg +1);
	if (r == NULL)
		return (NULL);
	if (neg == 1)
		r[0] = '-';
	r[dig + neg] = '\0';
	while (dig > 0)
	{
		r[(dig - 1) + neg] = (num % 10) + '0';
		num /= 10;
		dig--;
	}
	return (r);
}
