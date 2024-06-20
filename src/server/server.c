/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:34:25 by apaula-l          #+#    #+#             */
/*   Updated: 2024/06/19 22:18:04 by apaula-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_handle_signal(int signum, siginfo_t *info, void *context)
// função recebe sinal, informação como quem enviou e informações adicionais
{
	static unsigned char	character;
	static int				bit;
	static pid_t			client_pid;

	(void)context;
	if (client_pid != info->si_pid) // se o pid for de um novo client
	{
		bit = 0; // reseta bit
		character = 0; // reseta caracter
	}
	client_pid = info->si_pid; // guarda/atualiza pid do client
	if (signum == SIGUSR1) // se o sinal for SIGUSR1
		character += 1 << bit; // adiciona 1 ao caracter
	else
		character += 0 << bit; // move caracter para a esquerda
	// ft_printf("%d\n", character);
	bit++; // incrementa bit
	if (bit == 8) // verifica se completou 8 bits
	{
		write(1, &character, 1); // escreve caracter
		bit = 0; // reseta bit
		character = 0; // reseta caracter
	}
	kill(client_pid, SIGUSR2); // envia sinal de confirmação para o client
}

int	main(void)
{
	struct sigaction	sa; // estrutura especifíca como tratar sinais
	ft_printf("Server PID: %d\n", getpid()); // imprime pid do server
	sa.sa_sigaction = &ft_handle_signal; // função que manipula sinal
	sa.sa_flags = SA_SIGINFO; // flag para passar informações adicionais
	sigemptyset(&sa.sa_mask); // inicializa máscara de sinais (vazia)
	if ((sigaction(SIGUSR1, &sa, NULL) == -1)
		|| (sigaction(SIGUSR2, &sa, NULL) == -1))
// verifica se houve erro ao definir ação para sinais
	{
		ft_putendl_fd("Error: sigaction\n", STDERR_FILENO); // imprime mensagem de erro
		return (1); // retorna erro
	}
	// sigaction(SIGUSR1, &sa, NULL); // ação para SIGUSR1
	// sigaction(SIGUSR2, &sa, NULL); // ação para SIGUSR2
	while (1) // loop infinito
		pause(); // pausa execução até receber um sinal
	return (0);
}
