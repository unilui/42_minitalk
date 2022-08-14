/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:38:38 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/14 22:57:53 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal)
{
	printf("Recebi um sinal!\n");
	(void)signal;
}

int main(void)
{
	printf("%d\n", getpid());
	signal(SIGUSR1, &signal_handler);
	while (1)
	{
		
	}
	return (0);
}
