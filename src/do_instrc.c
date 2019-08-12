/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instrc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 06:18:08 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/12 13:28:03 by bnkosi           ###   ########.fr       */
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
	stack->prnt_instrc ? write(1, "sa\n", 3) : 0;
	if (stack->show_stack)
	{
		write(1, "A: ", 3);
		ft_print_array(stack->a_stack, stack->a_size);
		if (stack->b_size)
		{
			write(1, "B: ", 3);
			ft_print_array(stack->b_stack, stack->b_size);
		}
	}
	stack->res_instrc++;
}

void	do_sb(t_stack *stack)
{
	int tmp;

	if (stack->b_size < 2)
		return ;
	tmp = stack->b_stack[0];
	stack->b_stack[0] = stack->b_stack[1];
	stack->b_stack[1] = tmp;
	stack->prnt_instrc ? write(1, "sb\n", 3) : 0;
	if (stack->show_stack)
	{
		write(1, "A: ", 3);
		ft_print_array(stack->a_stack, stack->a_size);
		if (stack->b_size)
		{
			write(1, "B: ", 3);
			ft_print_array(stack->b_stack, stack->b_size);
		}
	}
	stack->res_instrc++;
}

void	do_ss(t_stack *stack)
{
	int tmp_instrc;
	int tmp_stack;

	tmp_instrc = stack->prnt_instrc;
	tmp_stack = stack->show_stack;
	stack->prnt_instrc = 0;
	stack->show_stack = 0;
	do_sa(stack);
	do_sb(stack);
	stack->prnt_instrc = tmp_instrc;
	stack->show_stack = tmp_stack;
	stack->prnt_instrc ? write(1, "ss\n", 3) : 0;
	if (stack->show_stack)
	{
		write(1, "B: ", 3);
		ft_print_array(stack->a_stack, stack->a_size);
		if (stack->b_size)
		{
			write(1, "B: ", 3);
			ft_print_array(stack->b_stack, stack->b_size);
		}
	}
	stack->res_instrc++;
}

void	do_pa(t_stack *stack)
{
	int i;

	if (stack->b_size == 0)
		return ;
	i = stack->a_size;
	while (i-- > 0)
		stack->a_stack[i + 1] = stack->a_stack[i];
	stack->a_stack[0] = stack->b_stack[0];
	i = 0;
	while (i++ <= stack->b_size)
		stack->b_stack[i - 1] = stack->b_stack[i];
	stack->a_size++;
	stack->b_size--;
	stack->prnt_instrc ? write(1, "pa\n", 3) : 0;
	if (stack->show_stack)
	{
		write(1, "A: ", 3);
		ft_print_array(stack->a_stack, stack->a_size);
		if (stack->b_size)
		{
			write(1, "B: ", 3);
			ft_print_array(stack->b_stack, stack->b_size);
		}
	}
	stack->res_instrc++;
}

void	do_pb(t_stack *stack)
{
	int i;

	if (stack->a_size == 0)
		return ;
	i = stack->b_size;
	while (i-- > 0)
		stack->a_stack[i - 1] = stack->a_stack[1];
	stack->b_size++;
	stack->a_size++;
	stack->prnt_instrc ? write(1, "pb\n", 3) : 0;
	if (stack->show_stack)
	{
		write(1, "A: ", 3);
		ft_print_array(stack->a_stack, stack->a_size);
		if (stack->b_size)
		{
			write(1, "B: ", 3);
			ft_print_array(stack->b_stack, stack->b_size);
		}
	}
	stack->res_instrc++;
}
