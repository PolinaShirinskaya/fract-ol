/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:31:30 by adian             #+#    #+#             */
/*   Updated: 2022/03/19 14:39:33 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cont_zero(const char *dest, size_t size)
{
	while (size)
	{
		if (*dest++ == 0)
			return (1);
		size--;
	}
	return (0);
}

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	destsrc_len;

	src_len = ft_strlen(src);
	if (ft_cont_zero(dest, destsize))
		dest_len = ft_strlen(dest);
	else
		return (destsize + src_len);
	if (destsize <= dest_len)
		return (destsize + src_len);
	else
	{
		destsrc_len = dest_len + src_len;
		dest = dest + dest_len;
		destsize = destsize - dest_len;
		while (*src && destsize > 1)
		{
			*dest++ = *src++;
			destsize--;
		}
		*dest = 0;
	}
	return (destsrc_len);
}
