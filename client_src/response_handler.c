/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   response_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 02:18:20 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/18 02:56:33 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	phase_handler(int phase)
{
	if (phase == 1)
	{
		g_connection.action.sa_handler = response_handler;
		g_connection.action.sa_flags = 0;
	}
	sigemptyset(&g_connection.action.sa_mask);
	sigaddset(&g_connection.action.sa_mask, SIGUSR1);
	sigaddset(&g_connection.action.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &g_connection.action, NULL);
	sigaction(SIGUSR2, &g_connection.action, NULL);
}

void	response_handler(int signal)
{
	(void)signal;
	g_connection.waiting = 0;
}
