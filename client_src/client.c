/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:00:15 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/24 01:24:32 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"
#include "libft.h"

t_cdata	g_cxn;

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		set_handlers();
		g_cxn.server_pid = ft_atoi(argv[1]);
		send_str(argv[2]);
		ft_printf("Message delivered!\n");
	}
	else
		ft_printf("Usage : ./client <Server_PID> <Message>\n");
	return (0);
}
