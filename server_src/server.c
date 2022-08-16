/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:38:38 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/16 03:00:31 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

typedef struct s_chr
{
	char		chr;
	short int	byte;
}	t_chr;

t_chr chr;

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
}

int main(void)
{
	printf("%d\n", getpid());
	signal(SIGUSR1, &signal_handler);
	signal(SIGUSR2, &signal_handler);
	while (1)
	{
		if (chr.byte)
		{
			printf("%c\n", chr.chr);
			chr.chr = 0;
			chr.byte = 0;
		}
	}
	return (0);
}
