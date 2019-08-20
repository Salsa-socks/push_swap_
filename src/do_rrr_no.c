/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rrr_no.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 11:58:10 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/20 12:17:54 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rra_no(t_stack *stack)
{
	int	i;
	int	tmp;

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
}

void	do_rrb_no(t_stack *stack)
{
	int	i;
	int	tmp;

	if (stack->b_size < 2)
		return ;
	i = stack->b_size - 1;
	tmp = stack->b_stack[i];
	while (i > 0)
	{
		stack->b_stack[i] = stack->b_stack[i - 1];
		i--;
	}
	stack->b_stack[0] = tmp;
}

void	do_rrr_no(t_stack *stacks)
{
	int	i;
	int	tmp;

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
}
