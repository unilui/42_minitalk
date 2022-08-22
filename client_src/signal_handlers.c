/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 02:18:20 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/22 01:49:43 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"

void	phase_handler(int phase)
{
	if (phase == 1)
		g_cxn.action.sa_sigaction = response_handler;
	g_cxn.action.sa_flags = SA_SIGINFO;;
	sigemptyset(&g_cxn.action.sa_mask);
	sigaction(SIGUSR1, &g_cxn.action, NULL);
	sigaction(SIGUSR2, &g_cxn.action, NULL);
	g_cxn.response.waiting = 1;
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
	while (g_cxn.response.waiting)
		usleep(10);
	g_cxn.response.waiting = 1;
}
