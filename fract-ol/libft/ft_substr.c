/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:31:30 by adian             #+#    #+#             */
/*   Updated: 2022/03/19 14:39:34 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	unsigned char	*substr;

	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
		return (ft_strdup(""));
	if ((start + len) > ft_strlen(str))
		len = ft_strlen(str) - start;
	substr = (unsigned char *)malloc((len + 1) * sizeof(char));
	if (substr != NULL)
	{
		ft_memcpy(substr, str + start, len);
		substr[len] = 0;
		return ((char *)(substr));
	}
	return (NULL);
}
