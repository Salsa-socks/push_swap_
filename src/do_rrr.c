/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 06:49:53 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/19 08:29:59 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rra(t_stack *stack)
{
	int i;
	int tmp;

	if (stack->a_size == 0)
		return ;
	i = stack->a_size - 1;
	tmp = stack->a_stack[i];
	while (i > 0)
	{
		stack->a_stack[i] = stack->a_stack[i - 1];
		i--;
	}
	stack->a_stack[0] = tmp;
	ft_putendl("rra");
}

void	do_rrb(t_stack *stack)
{
	int i;
	int tmp;

	if (stack->b_size == 0)
		return ;
	i = stack->b_size - 1;
	tmp = stack->b_stack[i];
	while (i > 0)
	{
		stack->b_stack[i] = stack->b_stack[i - 1];
		i--;
	}
	stack->b_stack[0] = tmp;
	ft_putendl("rrb");
}

void	do_rrr(t_stack *stacks)
{
	int i;
	int tmp;

	if (stacks->a_size > 1)
	{
		i = stacks->a_size - 1;
		tmp = stacks->a_stack[i];
		while (i-- > 0)
		{
			stacks->a_stack[i + 1] = stacks->a_stack[i];
		}
		stacks->a_stack[0] = tmp;
	}
	if (stacks->b_size > 1)
	{
		i = stacks->b_size - 1;
		tmp = stacks->b_stack[i];
		while (i > 0)
		{
			stacks->b_stack[i] = stacks->b_stack[i - 1];
			i--;
		}
		stacks->b_stack[0] = tmp;
	}
	ft_putendl("rrr");
}
