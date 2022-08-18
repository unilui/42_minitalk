/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 00:28:02 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/18 02:59:11 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_str(char *str, int pid)
{
	short int bit;

	g_connection.phase(1);
	while (*str)
	{
		bit = 7;
		while (bit >= 0)
		{
			g_connection.waiting = 1;
			send_bit((*str & (1 << bit)) >> bit, pid);
			bit--;
			while (g_connection.waiting)
				usleep(10);
		}
		str++;
		usleep(200);
	}
}
