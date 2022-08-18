/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_bit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 02:03:47 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/18 02:04:03 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(int bit, int pid)
{
	if (bit)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}
