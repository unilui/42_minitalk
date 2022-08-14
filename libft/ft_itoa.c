/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:28:00 by lufelip2          #+#    #+#             */
/*   Updated: 2022/06/08 18:40:40 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int nbr);

char	*ft_itoa(int n)
{
	char	*nbr;
	int		digits;
	int		i_nbr;

	digits = 1;
	i_nbr = n;
	while (i_nbr < -9 || i_nbr > 9)
	{
		i_nbr /= 10;
		digits++;
	}
	nbr = malloc(digits + (n < 0) + 1);
	if (nbr == NULL)
		return (NULL);
	if (n < 0)
		nbr[0] = '-';
	nbr[digits + (n < 0)] = '\0';
	while (digits--)
	{
		nbr[digits + (n < 0)] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (nbr);
}

static int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}
