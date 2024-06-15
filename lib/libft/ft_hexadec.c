/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 02:19:54 by apaula-l          #+#    #+#             */
/*   Updated: 2024/02/03 03:21:10 by apaula-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_puthex(unsigned int num, char specifier)
{
	int	count;

	count = 0;
	if (num == 0)
	{
		return (ft_putchar('0'));
	}
	count += ft_putchar('0');
	count += ft_putchar(specifier);
	if (specifier == 'x')
		count += ft_puthexlow(num);
	else if (specifier == 'X')
		count += ft_puthexupper(num);
	return (count);
}

int	ft_hexadec(unsigned int num, char specifier)
{
	if (specifier != 'x' && specifier != 'X')
		return (0);
	return (ft_puthex(num, specifier));
}
