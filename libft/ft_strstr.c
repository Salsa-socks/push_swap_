/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:35:05 by bnkosi            #+#    #+#             */
/*   Updated: 2019/05/31 15:08:05 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *ndl)
{
	unsigned int	i;
	unsigned int	j;

	if (ft_strlen(ndl) == 0)
		return ((char *)hay);
	i = 0;
	while (hay[i] != '\0')
	{
		j = 0;
		while (ndl[j] == hay[i + j] && hay[i + j] != '\0' && ndl[j] != '\0')
		{
			if (ndl[j + 1] == '\0')
				return ((char *)hay + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
