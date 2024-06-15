/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_positive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 00:45:45 by apaula-l          #+#    #+#             */
/*   Updated: 2024/02/03 02:37:19 by apaula-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_positive(int num)
{
	int	count;

	count = 0;
	if (num >= 0)
		count += ft_putchar('+');
	count += ft_putnbr(num);
	return (count);
}
