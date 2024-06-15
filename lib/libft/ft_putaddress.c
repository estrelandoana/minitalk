/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 07:54:13 by apaula-l          #+#    #+#             */
/*   Updated: 2024/02/02 21:13:50 by apaula-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putaddress(unsigned long n)
{
	int		num;
	char	*base;

	num = 0;
	base = "0123456789abcdef";
	if (n == 0)
		num += ft_putchar(base[0]);
	else if (n >= 16)
	{
		num += ft_putaddress(n / 16);
		num += ft_putaddress(n % 16);
	}
	else
		num += ft_putchar(base [n % 16]);
	return (num);
}

int	ft_checknill(unsigned long n)
{
	int		num;

	num = 0;
	if (n == 0)
		num += ft_putstr("(nil)");
	else
	{
		num += ft_putstr("0x");
		num += ft_putaddress(n);
	}
	return (num);
}
