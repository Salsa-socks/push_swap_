/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 13:51:03 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/16 13:54:40 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_stack *stack)
{
	register int max_idx;

	if (stack->a_size == 1)
		return ;
	if (stack->a_size == 2)
	{
		if (stack->a_stack[0] > stack->a_stack[1])
			do_sa(stack);
		return ;
	}
	else if (stack->a_size == 3)
	{
		max_idx = max_elem(stack->a_stack, stack->a_size);
		if (max_idx == 0)
			do_ra(stack);
		if (max_idx == 1)
			do_rra(stack);
		if (stack->a_stack[0] > stack->a_stack[1])
			do_sa(stack);
	}
}

void		sort(t_stack *stack)
{
	if (is_sorted(stack->a_stack, stack->a_size) && stack->b_size == 0)
		return ;
	if (stack->a_size <= 3)
		return (sort_3(stack));
	else
		global_sort(stack);
}
