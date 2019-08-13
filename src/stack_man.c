/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_man.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 07:48:53 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/13 07:50:52 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *stack, int len)
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

int rev_sorted(int *stack, int len)
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

void	free_stack(t_stack *stack)
{
	free(stack->a_stack);
	free(stack->b_stack);
	free(stack);
	stack = NULL;
}

void	free_moves(m_moves *moves)
{
	free(moves->art);
	free(moves->brt);
	free(moves->c_rot);
	free(moves);
	moves = NULL;
}
