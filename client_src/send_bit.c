/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_bit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 02:03:47 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/22 01:35:47 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"

void	send_bit(int bit)
{
	if (bit)
		kill(g_cxn.server_pid, SIGUSR1);
	else
		kill(g_cxn.server_pid, SIGUSR2);
}
