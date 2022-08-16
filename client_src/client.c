/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:00:15 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/16 03:02:58 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft.h"

# define LOW_BIT 0x01

void	send_chr(char chr, int pid)
{
	short int shift;

	shift = 7;
	while (shift >= 0)
	{
		if ((chr & (1 << shift)) >> shift)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		shift--;
		usleep(5);
	}
}

int main(int argc, char **argv)
{
	(void)argc;
	send_chr('A', ft_atoi(argv[1]));
	usleep(5);
	send_chr('B', ft_atoi(argv[1]));
	return (0);
}
