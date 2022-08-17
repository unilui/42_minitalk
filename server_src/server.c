/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:38:38 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/17 01:56:55 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

typedef struct s_chr
{
	char		chr;
	short int	byte;
}	t_chr;

t_chr chr;
struct sigaction newact;

void	signal_handler(int signal)
{
	static short int	bit_counter;
	if (signal == SIGUSR1)
	{
		chr.chr = chr.chr | 1;
		if (bit_counter < 7)
			chr.chr = chr.chr << 1;
		bit_counter++;
	}
	else
	{
		chr.chr = chr.chr | 0;
		if (bit_counter < 7)
			chr.chr = chr.chr << 1;
		bit_counter++;
	}
	if (bit_counter == 8)
	{
		chr.byte = 1;
		bit_counter = 0;
	}
	sigemptyset(&newact.sa_mask);
	sigaction(SIGUSR1, &newact, NULL);
	sigaction(SIGUSR2, &newact, NULL);
}

int main(void)
{
	newact.sa_handler = signal_handler;
	newact.sa_flags = 0;
	sigemptyset(&newact.sa_mask);
	sigaddset(&newact.sa_mask, SIGUSR1);
	sigaddset(&newact.sa_mask, SIGUSR2);
	printf("%d\n", getpid());
	sigaction(SIGUSR1, &newact, NULL);
	sigaction(SIGUSR2, &newact, NULL);
	while (1)
	{
		if (chr.byte)
		{
			printf("%c", chr.chr);
			chr.chr = 0;
			chr.byte = 0;
		}
	}
	return (0);
}
