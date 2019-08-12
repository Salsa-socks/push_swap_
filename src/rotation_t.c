/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_t.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 08:33:45 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/12 10:38:39 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		art(int len, int pos, char **a_rot)
{
	if (pos > len / 2)
	{
		*a_rot = ft_strcpy(*a_rot, "rra");
		if (len > 2)
			pos = len - pos;
	}
	else
		*a_rot = ft_strcpy(a_rot, "ra");
	return (pos);
}

int		brt(int len, int pos, char **b_rot)
{
	if (pos > len / 2)
	{
		*b_rot = ft_strcpy(*b_rot, "rrb");
		if (len > 2)
			pos = len - pos;
	}
	else
		*b_rot = ft_strcpy(b_rot, "rb");
	return (pos);
}
