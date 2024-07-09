/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:34:25 by apaula-l          #+#    #+#             */
/*   Updated: 2024/07/05 18:24:13 by apaula-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_handle_signal(int signum, siginfo_t *info, void *context)
{
	static unsigned char	character;
	static int				bit;
	static pid_t			client_pid;

	(void)context;
	if (client_pid != info->si_pid)
	{
		bit = 0;
		character = 0;
	}
	client_pid = info->si_pid;
	if (signum == SIGUSR1)
		character += 1 << bit;
	else
		character += 0 << bit;
	bit++;
	if (bit == 8)
	{
		write(1, &character, 1);
		bit = 0;
		character = 0;
	}
	kill(client_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = &ft_handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if ((sigaction(SIGUSR1, &sa, NULL) == -1)
		|| (sigaction(SIGUSR2, &sa, NULL) == -1))
	{
		ft_putendl_fd("Error: sigaction\n", STDERR_FILENO);
		return (1);
	}
	while (1)
		pause();
	return (0);
}
