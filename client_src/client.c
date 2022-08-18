/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:00:15 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/18 02:42:08 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"
#include "libft.h"

t_cdata	g_connection;

int main(int argc, char **argv)
{
	g_connection.phase = phase_handler;
	(void)argc;
	send_str(argv[2], ft_atoi(argv[1]));
	send_str("\n", ft_atoi(argv[1]));
	return (0);
}
