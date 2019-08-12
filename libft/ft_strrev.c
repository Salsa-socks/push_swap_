/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 10:05:40 by bnkosi            #+#    #+#             */
/*   Updated: 2019/06/05 10:41:04 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	c;

	i = 0;
	len = ft_strlen(str);
	while (len - 1 >= i)
	{
		c = str[i];
		str[i] = str[len - 1];
		str[len - 1] = c;
		len--;
		i++;
	}
	return (str);
}
