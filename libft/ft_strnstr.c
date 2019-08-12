/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 14:55:36 by bnkosi            #+#    #+#             */
/*   Updated: 2019/05/31 14:55:44 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *ndl, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (hay[0] == '\0')
		return (NULL);
	if (ndl[0] == '\0')
		return ((char *)hay);
	while (i < len && hay[i] != '\0')
	{
		j = 0;
		while (i + j < len && ndl[j] == hay[i + j] && ndl[j] != '\0')
			j++;
		if (ndl[j] == '\0')
			return ((char *)hay + i);
		i++;
	}
	return (NULL);
}
