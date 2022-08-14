/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:49:46 by lufelip2          #+#    #+#             */
/*   Updated: 2022/07/24 12:08:12 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_ptr(size_t nbr, char chr)
{
	const char	*base = "ABCDEF";
	static int	wrt;
	static int	track;
	int			tmp;
	int			lower_case;

	lower_case = 0;
	if (chr == 'x')
		lower_case = 32;
	if (nbr > 15)
	{
		track++;
		ft_put_ptr((nbr / 16), chr);
	}
	if (nbr % 16 > 9)
		wrt += ft_putchar(base[(nbr % 16) - 10] + lower_case);
	else
		wrt += ft_putchar((nbr % 16) + '0');
	if (track == 0)
	{
		tmp = wrt;
		wrt = 0;
		return (tmp);
	}
	return (track--);
}
