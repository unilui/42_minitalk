/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:38:38 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/22 02:53:04 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_server.h"
#include "libft.h"

t_sdata g_cxn;

int main(void)
{
	ft_printf("%d\n", getpid());
	g_cxn.phase = phase_handler;
	g_cxn.phase(1);
	while (1)
	{
	}
	return (0);
}
