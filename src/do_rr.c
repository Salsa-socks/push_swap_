/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 06:31:01 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/12 13:30:07 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra(t_stack *stack)
{
	int i;
	int tmp;

	i = 1;
	if (stack->a_size == 0)
		return ;
	tmp = stack->a_stack[0];
	while (i < stack->a_size)
	{
		stack->a_stack[i - 1] = stack->a_stack[i];
		i++;
	}
	stack->a_stack[i - 1] = tmp;
	stack->prnt_instrc ? write(1, "ra\n", 3) : 0;
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

void	do_rb(t_stack *stack)
{
	int i;
	int tmp;

	tmp = 0;
	i = 1;
	if (stack->b_size == 0)
		return ;
	while (i < stack->b_size)
	{
		stack->b_stack[i - 1] = stack->b_stack[i];
		i++;
	}
	stack->b_stack[i - 1] = tmp;
	stack->prnt_instrc ? write(1, "rb\n", 3) : 0;
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

void	do_rr(t_stack *stack)
{
	int	tmp_instrc;
	int tmp_stack;

	tmp_instrc = stack->show_stack;
	tmp_stack = stack->prnt_instrc;
	stack->prnt_instrc = 0;
	stack->show_stack = 0;
	do_ra(stack);
	do_rb(stack);
	stack->prnt_instrc = tmp_instrc;
	stack->show_stack = tmp_stack;
	stack->prnt_instrc ? write(1, "rr\n", 3) : 0;
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
