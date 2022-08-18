/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:38:38 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/18 02:58:03 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_server.h"

t_sdata g_connection;

void	signal_handler(int signal, siginfo_t *c_info, void *context)
{
	static short int	bit_counter;

	g_connection.chr |= (signal == SIGUSR1);
	if (bit_counter < 7)
		g_connection.chr <<= 1;
	bit_counter++;
	kill(c_info->si_pid, SIGUSR1);
	if (bit_counter == 8)
	{
		g_connection.byte = 1;
		bit_counter = 0;
	}
	(void)context;
}

int main(void)
{
	g_connection.action.sa_sigaction = signal_handler;
	g_connection.action.sa_flags = SA_SIGINFO;
	sigemptyset(&g_connection.action.sa_mask);
	printf("%d\n", getpid());
	sigaction(SIGUSR1, &g_connection.action, NULL);
	sigaction(SIGUSR2, &g_connection.action, NULL);
	while (1)
	{
		if (g_connection.byte)
		{
			printf("%c", g_connection.chr);
			g_connection.chr = 0;
			g_connection.byte = 0;
		}
	}
	return (0);
}
