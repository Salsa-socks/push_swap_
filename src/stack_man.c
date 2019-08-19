/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_man.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 07:48:53 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/19 08:49:09 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(int *stack, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (stack[i] < stack[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int		rev_sorted(int *stack, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (stack[i] > stack[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

void	del_stacks(t_stack **stacks)
{
	if (*stacks)
	{
		if ((*stacks)->a_stack)
			free((*stacks)->a_stack);
		if ((*stacks)->b_stack)
			free((*stacks)->b_stack);
		free(*stacks);
		*stacks = NULL;
	}
}

void	free_stack(t_stack *stack)
{
	free(stack->a_stack);
	free(stack->b_stack);
	free(stack);
	stack = NULL;
}

void	free_moves(t_moves *moves)
{
	free(moves->art);
	free(moves->brt);
	free(moves->c_rot);
	free(moves);
	moves = NULL;
}
