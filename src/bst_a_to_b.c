/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_a_to_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 12:03:34 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/16 13:52:48 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		find_in_b(int *stack, int l, int el, char **rot_type)
{
	int			i;
	int			place;

	i = 0;
	place = 0;
	if (l == 2 && el > stack[0] && el < stack[1])
		place = 0;
	else if (l == 2 && el < stack[0] && el > stack[1])
		place = 1;
	else if (el > stack[max_elem(stack, l)] || el < stack[min_elem(stack, l)])
		place = max_elem(stack, l);
	else
		while (i < l)
		{
			if (el < stack[i] && ((i + 1 < l && el > stack[i + 1]) 
						|| (i + 1 == l && el > stack[0])))
			{
				place = i + 1;
				break;
			}
			i++;
		}
	return (brt(l, place, rot_type));
}

static int			find_com(m_moves *moves)
{
	int com;

	com = 0;
	if ((ft_strequ(moves->art, "rra") && (ft_strequ(moves->brt, "rrb")))
			|| (ft_strequ(moves->art, "ra") && (ft_strequ(moves->brt, "rb"))))
	{
		com = (moves->a_moves > moves->b_moves ? moves->b_moves : moves->a_moves);
		if (com)
		{
			moves->c_rot = ft_strcpy(moves->c_rot, moves->art);
			moves->c_rot[ft_strlen(moves->c_rot) - 1] = 'r';
			moves->b_moves -= com;
			moves->a_moves -= com;
		}
	}
	return (com);
}

static m_moves		*calc_a_to_b(t_stack *stack, int pos)
{
	m_moves *moves;

	moves = (m_moves *)malloc(sizeof(m_moves));
	moves->art = ft_strnew(3);
	moves->brt = ft_strnew(3);
	moves->c_rot = ft_strnew(3);
	moves->elem = stack->a_stack[pos];
	moves->a_moves = art(stack->a_size, pos, &(moves->art));
	moves->b_moves = find_in_b(stack->b_stack, stack->b_size,
	stack->a_stack[pos], &(moves->brt));
	moves->c_moves = find_com(moves);
	moves->result = moves->a_moves + moves->b_moves + moves->c_moves + 1;
	return (moves);
}

m_moves			*bst_a_to_b(t_stack *stack)
{
	int			i;
	m_moves		*bst_move;
	m_moves		*moves;

	i = 0;
	while (i < stack->a_size)
	{
		moves = calc_a_to_b(stack, i);
		if (i == 0)
			bst_move = moves;
		else if (bst_move->result > moves->result)
		{
			free_moves(bst_move);
			bst_move = moves;
		}
		else
			free_moves(moves);
		i++;
	}
	return (bst_move);
}
