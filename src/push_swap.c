/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 10:08:43 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/17 10:33:03 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **av)
{
	t_stack	*stacks;

	if (ac > 1)
	{
		stacks = (t_stack *)malloc(sizeof(t_stack));
		check_av(stacks, av, ac);
		sort(stacks);
		del_stacks(&stacks);
	}
	return (0);
}
