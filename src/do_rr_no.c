/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rr_no.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 11:57:14 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/20 12:01:26 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    do_ra_no(t_stack *stack)
{
        int i;
        int tmp;

        if (stack->a_size == 0)
                return ;
        i = 1;
        tmp = stack->a_stack[0];
        while (i < stack->a_size)
        {
                stack->a_stack[i - 1] = stack->a_stack[i];
                i++;
        }
        stack->a_stack[i - 1] = tmp;
}

void    do_rb_no(t_stack *stack)
{
        int i;
        int tmp;

        if (stack->b_size < 2)
                return ;
        i = 1;
        tmp = stack->b_stack[0];
        while (i < stack->b_size)
        {
                stack->b_stack[i - 1] = stack->b_stack[i];
                i++;
        }
        stack->b_stack[i - 1] = tmp;
}

void    do_rr_no(t_stack *stacks)
{
        int i;
        int tmp;

        if (stacks->a_size > 1)
        {
                i = 1;
                tmp = stacks->a_stack[0];
                while (i++ < stacks->a_size)
                {
                        stacks->a_stack[i - 2] = stacks->a_stack[i - 1];
                }
                stacks->a_stack[i - 2] = tmp;
        }
        if (stacks->b_size > 1)
        {
                i = 1;
                tmp = stacks->b_stack[0];
                while (i < stacks->b_size)
                {
                        stacks->b_stack[i - 1] = stacks->b_stack[i];
                        i++;
                }
                stacks->b_stack[i - 1] = tmp;
        }
}
