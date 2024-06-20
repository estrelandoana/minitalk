/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 04:04:59 by apaula-l          #+#    #+#             */
/*   Updated: 2024/02/03 02:37:00 by apaula-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_format(const char format, va_list arg)
{
	int	count;

	count = 0;
	if (format == 'c')
		count = ft_putchar(va_arg(arg, int));
	else if (format == 's')
		count = ft_putstr(va_arg(arg, char *));
	else if (format == 'd' || format == 'i')
		count = ft_putnbr(va_arg(arg, int));
	else if (format == 'u')
		count = ft_putunbr(va_arg(arg, unsigned int));
	else if (format == 'x')
		count = ft_puthexlow(va_arg(arg, unsigned int));
	else if (format == 'X')
		count = ft_puthexupper(va_arg(arg, unsigned int));
	else if (format == 'p')
		count += ft_checknill(va_arg(arg, unsigned long long));
	else if (format == '%')
		count = ft_putchar('%');
	return (count);
}

static int	ft_verify_flag(const char *format, va_list arg, int *i)
{
	int	count;

	count = 0;
	if (format[++(*i)] == '+' && ft_strchr("di", format[*i + 1]))
	{
		count += ft_positive(va_arg(arg, int));
		(*i)++;
	}
	else if (format[*i] == '#' && ft_strchr("xX", format[*i + 1]))
	{
		count += ft_hexadec(va_arg(arg, unsigned int), format[*i + 1]);
		(*i)++;
	}
	else
		count += ft_format(format[*i], arg);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		count;

	i = -1;
	count = 0;
	va_start(arg, format);
	if (format == NULL)
		return (-1);
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
			count += ft_verify_flag(format, arg, &i);
		else
			count += ft_putchar(format[i]);
	}
	va_end(arg);
	return (count);
}
