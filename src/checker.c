/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 06:54:30 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/16 08:17:37 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	do_rot(t_stack *stacks, char *in)
{
	if (in[2] == '\0')
		do_rr(stacks);
	else if (in[2] == 'a' && in[3] == '\0')
		do_rra(stacks);
	else if (in[2] == 'b' && in[3] == '\0')
		do_rrb(stacks);
	else if (in[2] == 'r' && in[3] == '\0')
		do_rrr(stacks);
	else
		return (-1);
	return (0);
}

static	int	do_ins(t_stack *stacks, char *in)
{
	if (ft_strnequ(in, "rr", 2))
	{
		if (do_rot(stacks, in))
			return (-1);
	}
	else if (ft_strequ(in, "sa"))
		do_sa(stacks);
	else if (ft_strequ(in, "sb"))
		do_sb(stacks);
	else if (ft_strequ(in, "ss"))
		do_ss(stacks);
	else if (ft_strequ(in, "pa"))
		do_pa(stacks);
	else if (ft_strequ(in, "pb"))
		do_pb(stacks);
	else if (ft_strequ(in, "ra"))
		do_ra(stacks);
	else if (ft_strequ(in, "rb"))
		do_rb(stacks);
	else
		return (-1);
	return (0);
}

static void	get_ins(t_stack *stacks)
{
	char *in;

	in = NULL;
	while (get_next_line(0, &in) > 0)
	{
		if (do_ins(stacks, in))
		{
			ft_putstr_fd("Error\n", 2);
			del_stacks(&stacks);
			ft_strdel(&in);
			exit(1);
		}
		ft_strdel(&in);
	}
}

int			main(int ac, char **av)
{
	t_stack	*stacks;

	if (ac > 1)
	{
		stacks = (t_stack *)malloc(sizeof(t_stack));
		check_av(stacks, av, ac);
		get_ins(stacks);
		if (is_sorted(stacks->a_stack, stacks->a_size) && stacks->b_size == 0)
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
		del_stacks(&stacks);
	}
	return (0);
}
