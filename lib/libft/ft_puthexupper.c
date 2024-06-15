/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 07:38:30 by apaula-l          #+#    #+#             */
/*   Updated: 2024/02/03 02:58:02 by apaula-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthexupper(unsigned int n)
{
	int		num;
	char	*base;

	num = 0;
	base = "0123456789ABCDEF";
	if (n >= 16)
	{
		num += ft_puthexupper(n / 16);
		num += ft_puthexupper(n % 16);
	}
	else
	{
		num += ft_putchar(base [n % 16]);
	}
	return (num);
}
