/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:00:15 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/17 04:08:27 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft.h"

typedef struct s_cdata {
	short int	waiting;
}	t_cdata;

t_cdata	data;

void	signal_handler(int signal)
{
	(void)signal;
	data.waiting = 0;
}

void	send_chr(char chr, int pid)
{
	short int shift;

	shift = 7;
	while (shift >= 0)
	{
		data.waiting = 1;
		if ((chr & (1 << shift)) >> shift)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		shift--;
		while (data.waiting)
			usleep(10);
	}
}

void	send_str(char *str, int pid)
{
	while (*str)
	{
		send_chr(*str, pid);
		str++;
		usleep(200);
	}
	send_chr('\n', pid);
}

int main(int argc, char **argv)
{
	struct sigaction newact;

	newact.sa_handler = signal_handler;
	newact.sa_flags = 0;
	sigemptyset(&newact.sa_mask);
	sigaddset(&newact.sa_mask, SIGUSR1);
	sigaddset(&newact.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &newact, NULL);
	sigaction(SIGUSR2, &newact, NULL);
	(void)argc;
	send_str(argv[2], ft_atoi(argv[1]));
	return (0);
}
