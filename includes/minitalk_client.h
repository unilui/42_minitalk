/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:04:09 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/22 01:51:44 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_CLIENT_H
# define MINITALK_CLIENT_H

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

typedef struct s_response {
	void		(*wait)(void);
	short int	waiting;
}	t_response;

typedef struct s_cdata {
	t_response	response;
	char		*message;
	int			server_pid;
	void		(*phase)(int);
	struct sigaction action;
}	t_cdata;

extern t_cdata g_cxn;

void	phase_handler(int phase);
void	send_str(char *str);
void	send_bit(int bit);
void	response_handler(int signal, siginfo_t *c_info, void *context);
void	waiting_handler(void);

#endif
