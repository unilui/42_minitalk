/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:30:47 by lufelip2          #+#    #+#             */
/*   Updated: 2022/07/24 12:08:10 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	t_str	str_args;

	va_start(str_args.args, str);
	str_args.written = 0;
	if (str)
	{
		while (*str)
		{
			str_args.chr = *str;
			replace_handler(&str_args);
			str++;
		}
	}
	va_end(str_args.args);
	return (str_args.written);
}
