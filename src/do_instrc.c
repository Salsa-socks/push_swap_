/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instrc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 06:18:08 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/19 08:33:07 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(t_stack *stack)
{
	int tmp;

	if (stack->a_size < 2)
		return ;
	tmp = stack->a_stack[0];
	stack->a_stack[0] = stack->a_stack[1];
	stack->a_stack[1] = tmp;
	ft_putendl("sa");
}

void	do_sb(t_stack *stack)
{
	int tmp;

	if (stack->b_size < 2)
		return ;
	tmp = stack->b_stack[0];
	stack->b_stack[0] = stack->b_stack[1];
	stack->b_stack[1] = tmp;
	ft_putendl("sb");
}

void	do_ss(t_stack *stacks)
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
	ft_putendl("ss");
}

void	do_pa(t_stack *stack)
{
	int i;

	if (stack->b_size == 0)
		return ;
	i = stack->a_size;
	while (i--)
		stack->a_stack[i + 1] = stack->a_stack[i];
	stack->a_stack[0] = stack->b_stack[0];
	i = 0;
	while (i++ <= stack->b_size - 1)
		stack->b_stack[i - 1] = stack->b_stack[i];
	stack->a_size++;
	stack->b_size--;
	ft_putendl("pa");
}

void	do_pb(t_stack *stack)
{
	int i;

	if (stack->a_size == 0)
		return ;
	i = stack->b_size;
	while (i--)
		stack->b_stack[i + 1] = stack->b_stack[i];
	stack->b_stack[0] = stack->a_stack[0];
	i = 0;
	while (i++ <= stack->a_size - 1)
		stack->a_stack[i - 1] = stack->a_stack[i];
	stack->b_size++;
	stack->a_size--;
	ft_putendl("pb");
}
