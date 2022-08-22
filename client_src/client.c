/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:00:15 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/22 02:04:22 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"
#include "libft.h"

t_cdata	g_cxn;

int main(int argc, char **argv)
{
	(void)argc;
	g_cxn.message = argv[2];
	g_cxn.server_pid = ft_atoi(argv[1]);
	g_cxn.phase = phase_handler;
	g_cxn.response.wait = waiting_handler;
	send_str(g_cxn.message);
	return (0);
}
