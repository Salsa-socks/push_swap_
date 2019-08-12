/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 10:53:03 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/11 11:36:13 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_in_a(int *stack, int len, int elem, char **rot_type)
{
	int 	i;
	int 	place;

	i = 0;
	place = 0;
	if(len == 2 && elem > stack[0] && elem < stack[1])
		place = -1;
	else if (len == 2 && elem < stack[0] && elem > stack[1])
		place = 0;
	else if (elem > stack[max_elem(stack, len)] || elem < stack[min_elem(stack, len)])
		place = min_elem(stack, len);
	else
		while (i < len)
		{
			if (elem > stack[i] && ((i + 1 < len && elem < stack[i + 1]) || (i + 1 == len && elem < stack[0])))
			{
				place = i + 1;
				break
			}
			i++;
		}
	return (a_rot_type(len, place, rot_type));
}

static void	insert_in_a(t_stack *stack)
{
	int		rot_num;
	char	*rot_type;

	rot_num = 0;
	rot_type = ft_strnew(3);
	while (stack->b_size)
	{
		rot_num = find_in_a(stack->a_stack,stack->a_size, stack->b_stack[0], &rot_type);
		while (rot_num > 0)
		{
			if (ft_strequ(rot_type, "ra"))
				do_ra(stack);
			else
				do_rra(stack);
			rot_num--;
		}
		do_pa(stack);
	}
	first_a(stack);
	free(rot_type);
}

static void insert_in_b(t_stack *stack)
{
	int indx;

	indx = 0;
	while(stack->a_size > 2)
	{
		indx = min_elem(stack->a_stack, stack-.a_size);
		if (indx == 0)
			do_pb(stack);
		else if (indx <= stack->a_size / 2)
			do_ra(stack);
		else if (indx > stack->a_size / 2)
			do_rra(stack);
	}
}

static void	process_moves(m_moves *bst_move, t_stack *stack)
{
	while (bst_move->a_moves)
	{
		if (ft_strequ(bst_move->a_rot_type, "rb"))
			do_rb(stack);
		else
			do_rra(stack);
		bst_move->b_moves--;
	}
}

void		global_sort(t_stack *stack)
{
	m_moves *bst_move;
	int		bestest;

	bestest = (stack->a_size > 200) ? 50: 2;
	while (stack->b_size != 2)
		do_pb(stack);
	while (stack->a_size > bestest)
	{
		bst_move = bst_a_to_b(stack);
		while (bst_move->c_moves)
		{
			if (ft_strequ(bst_move->c_rot, "rr"))
				do_rr(stack);
			else
				do_rrr(stack);
			bst_move->c_moves--;
		}
		process_moves(bst_move, stack);
		do_pb(stack);
		free_moves(bst_move);
	}
	insert_in_b(stack);
	insert_in_a(stack);
}
