/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 00:28:02 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/22 02:48:02 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"

void	send_str(char *str)
{
	short int bit;

	g_cxn.phase(1);
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
