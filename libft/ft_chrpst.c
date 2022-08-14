/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrpst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 03:44:34 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/11 12:52:20 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_chrpst(char const *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (*s)
	{
		if (*s == (char)c)
			return (i);
		s++;
		i++;
	}
	if (*s == (char)c)
		return (i);
	return (-1);
}
