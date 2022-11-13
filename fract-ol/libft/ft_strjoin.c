/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:31:30 by adian             #+#    #+#             */
/*   Updated: 2022/03/19 14:39:33 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	size_t			str1_len;
	size_t			str2_len;
	size_t			str1str2_len;
	unsigned char	*ret;

	if (!str1 && !str2)
		return (ft_strdup(""));
	if (!str1)
		return (ft_strdup(str2));
	if (!str2)
		return (ft_strdup(str1));
	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	str1str2_len = str1_len + str2_len;
	ret = malloc((str1str2_len + 1) * sizeof(char));
	if (ret != NULL)
	{
		ft_memcpy(ret, str1, str1_len);
		ft_memcpy(ret + str1_len, str2, str2_len);
		ret[str1str2_len] = 0;
		return ((char *)(ret));
	}
	return (NULL);
}
