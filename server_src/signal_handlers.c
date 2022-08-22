/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 02:10:23 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/22 02:52:52 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_server.h"
#include "libft.h"

void	phase_handler(int phase)
{
	if (phase == 1)
		g_cxn.action.sa_sigaction = signal_handler;
	g_cxn.action.sa_flags = SA_SIGINFO;;
	sigemptyset(&g_cxn.action.sa_mask);
	sigaction(SIGUSR1, &g_cxn.action, NULL);
	sigaction(SIGUSR2, &g_cxn.action, NULL);
}

void	signal_handler(int signal, siginfo_t *c_info, void *context)
{
	static short int	bit_counter;

	g_cxn.chr |= (signal == SIGUSR1);
	if (bit_counter < 7)
		g_cxn.chr <<= 1;
	bit_counter++;
	kill(c_info->si_pid, SIGUSR1);
	if (bit_counter == 8)
	{
		ft_printf("%c", g_cxn.chr);
		bit_counter = 0;
		g_cxn.chr = 0;
	}
	(void)context;
}
