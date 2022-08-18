/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:04:09 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/18 02:53:32 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h> // Remover!!

typedef struct s_cdata {
	short int	waiting;
	void		(*phase)(int);
	struct sigaction action;
}	t_cdata;

extern t_cdata g_connection;

void	phase_handler(int phase);
void	send_str(char *str, int pid);
void	send_bit(int bit, int pid);
void	send_bit(int bit, int pid);
void	response_handler(int signal);

#endif
