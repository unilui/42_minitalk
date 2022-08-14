/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:00:15 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/15 01:40:39 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft.h"

# define LOW_BIT 0x01

int main(int argc, char **argv)
{
	unsigned char a;
	short int left_shift;

	a = 'C';
	left_shift = 7;
	while (left_shift >= 0)
	{
		printf("%d", ((a & (1 << left_shift)) >> left_shift));
		left_shift--;
	}
	(void)argc;
	(void)argv;
	//kill(ft_atoi(argv[1]), SIGUSR1);
	return (0);
}
