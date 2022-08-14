/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:15:29 by lufelip2          #+#    #+#             */
/*   Updated: 2022/06/05 19:16:12 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	x;
	size_t	little_len;

	i = 0;
	x = 0;
	little_len = ft_strlen(little);
	if (!little_len)
		return ((char *)big);
	while (big[i] && (i < len))
	{
		while (x < (len - i) && (big[i + x] == little[x]))
			x++;
		if (x == little_len)
			return ((char *)(big += i));
		x = 0;
		i++;
	}
	return (NULL);
}
