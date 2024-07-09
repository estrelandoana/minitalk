/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:58:45 by apaula-l          #+#    #+#             */
/*   Updated: 2024/07/05 19:03:36 by apaula-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static int	g_confirm_signal = 0;

void	ft_resp_handler(int signum)
{
	g_confirm_signal = 1;
	(void) signum;
}

void	ft_send_bit(int pid, int bit)
{
	int	signal;

	if (bit == 1)
		signal = SIGUSR1;
	else
		signal = SIGUSR2;
	if (kill(pid, signal) == -1)
	{
		ft_putstr_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	while (!g_confirm_signal)
		;
	g_confirm_signal = 0;
}

void	ft_send_char(int pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		ft_send_bit(pid, (c >> i) & 1);
		i++;
	}
}

void	ft_send_string(int pid, const char *str)
{
	while (*str)
		ft_send_char(pid, *str++);
	ft_send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client [PID] [string]\n", 2);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_putstr_fd("Invalid PID\n", 2);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR2, ft_resp_handler);
	ft_send_string(pid, argv[2]);
	ft_printf("Message received\n");
	return (0);
}
