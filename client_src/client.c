/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:00:15 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/17 02:07:05 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft.h"

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
		usleep(200);
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
	(void)argc;
	send_str(argv[2], ft_atoi(argv[1]));
	return (0);
}
