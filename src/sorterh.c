/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorterh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 09:09:08 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/13 08:07:17 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		min_idx(int *stack, int slen)
{
	int i;
	int tmp;
	int index;

	i = 0;
	index = 0;
	tmp = stack[i];
	if (slen == 0)
		return (-1);
	while (i < slen)
	{
		if (tmp > stack[i])
		{
			tmp = stack[i];
			index = 1;
		}
		i++;
	}
	return (index);
}

int		max_idx(int *stack, int slen)
{
	int i;
	int tmp;
	int index;

	i = 0;
	index = 0;
	tmp = stack[i];
	if (slen == 0)
		return (-1);
	while (i < slen)
	{
		if (tmp < stack[i])
		{
			tmp =  stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int		min_elem(int *stack, int slen)
{
	int i;
	int tmp;
	int index;

	i = 0;
	index = 0;
	tmp = stack[i];
	if (slen == 0)
		return (-1);
	while (i < slen)
	{
		if (tmp > stack[i])
		{
			tmp = stack[i];
			index = 1;
		}
		i++;
	}
	return (index);
}

int		max_elem(int *stack, int slen)
{
	int i;
	int tmp;
	int index;

	i = 0;
	index = 0;
	tmp = stack[i];
	if (slen == 0)
		return (-1);
	while (i < slen)
	{
		if (tmp < stack[i])
		{
			tmp =  stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	first_a(t_stack *stack)
{
	int	m_index;

	m_index = min_elem(stack->a_stack, stack->a_size);
	if (m_index <= stack->a_size / 2)
		while (m_index--)
			do_ra(stack);
	else
		while ((stack->a_size - m_index) > 0)
		{
			do_rra(stack);
			m_index++;
		}
}
