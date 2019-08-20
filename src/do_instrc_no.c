/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instrc_no.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 11:54:05 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/20 12:16:19 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa_no(t_stack *stack)
{
	int	tmp;

	if (stack->a_size < 2)
		return ;
	tmp = stack->a_stack[0];
	stack->a_stack[0] = stack->a_stack[1];
	stack->a_stack[1] = tmp;
}

void	do_sb_no(t_stack *stack)
{
	int	tmp;

	if (stack->b_size < 2)
		return ;
	tmp = stack->b_stack[0];
	stack->b_stack[0] = stack->b_stack[1];
	stack->b_stack[1] = tmp;
}

void	do_ss_no(t_stack *stacks)
{
	int	tmp;

	if (stacks->a_size > 1)
	{
		tmp = stacks->a_stack[0];
		stacks->a_stack[0] = stacks->a_stack[1];
		stacks->a_stack[1] = tmp;
	}
	if (stacks->b_size > 1)
	{
		tmp = stacks->b_stack[0];
		stacks->b_stack[0] = stacks->b_stack[1];
		stacks->b_stack[1] = tmp;
	}
}

void	do_pa_no(t_stack *stack)
{
	int	i;

	if (stack->b_size == 0)
		return ;
	i = stack->a_size;
	while (i-- > 0)
		stack->a_stack[i + 1] = stack->a_stack[i];
	stack->a_stack[0] = stack->b_stack[0];
	i = 0;
	while (i++ <= stack->b_size - 1)
		stack->b_stack[i - 1] = stack->b_stack[i];
	stack->a_size++;
	stack->b_size--;
}

void	do_pb_no(t_stack *stack)
{
	int	i;

	if (stack->a_size == 0)
		return ;
	i = stack->b_size;
	while (i-- > 0)
		stack->b_stack[i + 1] = stack->b_stack[i];
	stack->b_stack[0] = stack->a_stack[0];
	i = 0;
	while (i++ <= stack->a_size - 1)
		stack->a_stack[i - 1] = stack->a_stack[i];
	stack->b_size++;
	stack->a_size--;
}
