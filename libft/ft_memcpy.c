/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:40:37 by lufelip2          #+#    #+#             */
/*   Updated: 2022/06/08 21:37:05 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*us_dst;
	unsigned char	*us_src;

	i = 0;
	us_dst = (unsigned char *)dst;
	us_src = (unsigned char *)src;
	while (i < n)
	{
		us_dst[i] = us_src[i];
		i++;
	}
	return (dst);
}
