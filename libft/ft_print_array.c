/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 10:13:06 by bnkosi            #+#    #+#             */
/*   Updated: 2019/07/21 10:17:29 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_array(int *array, int ary_size)
{
	int i;

	i = 0;
	if (ary_size > 0)
		ft_putchar('[');
	while (i < ary_size)
	{
		if (i + 1 == ary_size)
		{
			ft_putnbr(array[i]);
			ft_putstr("]\n");
		}
		else
		{
			ft_putnbr(array[i]);
			ft_putstr(", ");
		}
		i++;
	}
}
