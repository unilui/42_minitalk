/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 02:41:23 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/18 02:48:32 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_SERVER_H
# define MINITALK_SERVER_H

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h> // Remover!!

typedef struct s_sdata {
	void		(*phase)(int);
	struct sigaction action;
	char		chr;
	short int	byte;
}	t_sdata;

extern t_sdata g_connection;

#endif