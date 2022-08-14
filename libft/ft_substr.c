/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 03:45:49 by lufelip2          #+#    #+#             */
/*   Updated: 2022/07/24 16:41:30 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	unsigned int	s_len;

	i = 0;
	if (len == 0)
		return (NULL);
	s_len = ft_strlen(s);
	if (start < s_len)
		str = malloc(s_len - start + 1);
	else
		str = malloc(1);
	if (str == NULL)
		return (NULL);
	while (s[start + i] && i < len && start < s_len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
