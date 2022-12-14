/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 02:41:23 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/24 01:02:59 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_SERVER_H
# define MINITALK_SERVER_H

# include <sys/types.h>
# include <signal.h>
# include <unistd.h>

typedef struct s_sdata {
	struct sigaction	action;
	char				chr;
}	t_sdata;

extern t_sdata	g_cxn;

void	signal_handler(int signal, siginfo_t *c_info, void *context);
void	set_handler(void);

#endif
