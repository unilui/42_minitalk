/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 02:18:20 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/24 01:44:12 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"
#include "libft.h"

void	set_handlers(void)
{
	g_cxn.response.wait = waiting_handler;
	g_cxn.response.waiting = 1;
	g_cxn.action.sa_sigaction = response_handler;
	g_cxn.action.sa_flags = SA_SIGINFO;
	sigemptyset(&g_cxn.action.sa_mask);
	sigaction(SIGUSR1, &g_cxn.action, NULL);
	sigaction(SIGUSR2, &g_cxn.action, NULL);
}

void	response_handler(int signal, siginfo_t *c_info, void *context)
{
	if (c_info->si_pid != g_cxn.server_pid)
		return ;
	g_cxn.response.waiting = 0;
	(void)signal;
	(void)context;
}

void	waiting_handler(void)
{
	static int	time_spent;

	while (g_cxn.response.waiting)
	{
		usleep(10);
		time_spent++;
		if (time_spent == 500)
		{
			ft_printf("Server took too long to respond :/\n");
			exit(1);
		}
	}
	time_spent = 0;
	g_cxn.response.waiting = 1;
}

void	send_bit(int bit)
{
	if (bit)
	{
		if (kill(g_cxn.server_pid, SIGUSR1) == -1)
		{
			ft_printf("The server is offline or the PID is incorrect.\n");
			exit(1);
		}
	}
	else
	{
		if (kill(g_cxn.server_pid, SIGUSR2) == -1)
		{
			ft_printf("The server is offline or the PID is incorrect.\n");
			exit(1);
		}
	}
}

void	send_str(char *str)
{
	short int	bit;

	while (*str)
	{
		bit = 7;
		while (bit >= 0)
		{
			send_bit((*str & (1 << bit)) >> bit);
			bit--;
			g_cxn.response.wait();
		}
		str++;
		usleep(200);
	}
	bit = 7;
	while (bit >= 0)
	{
		send_bit(('\n' & (1 << bit)) >> bit);
		bit--;
		g_cxn.response.wait();
	}
}
