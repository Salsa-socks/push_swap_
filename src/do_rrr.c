/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 06:49:53 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/12 06:51:32 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void do_rra(t_stack, *stack)
{
	int i;
	int tmp;

	if (stack->a_size == 0)
		return;
	i = stack->a_size - 1;
	tmp = stack->a_stack[i];
	while (i > 0)
	{
		stack->a_stack[i] = stack->a_stack[i - 1];
		i--;
	}
	stack->a_stack[0] = tmp;
	stack->prnt_instrc ? write(1, "rra\n", 4) : 0;
	if (stack->show_stack)
	{
		ft_putstr("A: ");
		ft_print_array(stack->a_stack, stack->a_size);
		if (stack->b_size)
		{
			ft_putstr("A: ");
			ft_print_array(stack->b_stack, stack->b_size);
		}
	}
	stack->res_instrc++;
}

void	do_rrb(t_stack, *stack)
{
	int i;
	int tmp;

	if (stack->b_size ==0)
		return ;
	i = stack->b_size - 1;
	tmp = stack->b_stack[i];
	while (i > 0)
	{
		stack->b_stack[i] = stack->b_stack[i - 1];
		i--;
	}
	stack->b_stack[0] = tmp;
	stack->prnt_instrc ? write(1, "rrb\n", 4): 0;
	if (stack->show_stack)
	{
		ft_putstr("A: ");
		ft_print_array(stack->a_stack, stack->a_size);
		if (stack->b_size)
		{
			ft_putstr("B: ");
			ft_print_array(stack->b_stack, stack->b_size);
		}
	}
	stack->res_instrc++;
}

void	do_rrr(t_stack, *stack)
{
	int	tmp_instrc;
	int	tmp_stack;

	tmp_stack = stack->show_stack;
	tmp_instrc = stack->prnt_instrc;
	stack->prnt_instrc = 0;
	stack->show_stack = 0;
	do_rra(stack);
	do_rrb(stack);
	stack->prnt_instrc = tmp_instrc;
	stack->show_stack = tmp_stack;
	stack->prnt_instrc ? write(1, "rrr\n", 4): 0;
	if (stack->show_stack)
	{
		ft_putstr("A: ");
		ft_print_array(stack->a_stack, stack->a_size);
		if (stack->b_size)
		{
			ft_putstr("B: ");
			ft_print_array(stack->b_stack, stack->b_size);
		}
	}
	stack->res_instrc++;
}
