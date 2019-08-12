/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 06:54:30 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/12 13:16:06 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
static int	get_instruction(t_stack *stack, char *instr)
{
	if (ft_strequ(instr, "sa"))
		do_sa(stack);
	else if (ft_strequ(instr, "sb"))
		do_sb(stack);
	else if (ft_strequ(instr, "ss"))
		do_ss(stack);
	else if (ft_strequ(instr, "pa"))
		do_pa(stack);
	else if (ft_strequ(instr, "pb"))
		do_pb(stack);
	else if (ft_strequ(instr, "ra"))
		do_ra(stack);
	else if (ft_strequ(instr, "rb"))
		do_rb(stack);
	else if (ft_strequ(instr, "rr"))
		do_rr(stack);
	else if (ft_strequ(instr, "rra"))
		do_rra(stack);
	else if (ft_strequ(instr, "rrb"))
		do_rrb(stack);
	else if (ft_strequ(instr, "rrr"))
		do_rrr(stack);
	else
		return (-1);
	return (0);
}*/
/*
static void	do_instrc(t_stack *stack)
{
	char *instrc;

	while (get_next_line(0, &instrc) > 0)
	{
		if (!instrc)
			break;
		if (get_instruction(stack, instrc))
		{
			ft_putstr_fd("Error\n", 2);
			free_stack(stack);
			free(instrc);
			exit(1);
		}
		free(instrc);
		instrc = NULL;
	}
	free (instrc);
}*/

static void	split_args(int argc, char **argv, t_stack *stack)
{
	argv = ft_strsplit(argv[0], ' ');
	argc = 0;
	while (argv && argv[argc])
		argc++;
	if (argc == 0)
	{
		ft_putstr_fd("Error\n", 2);
		free(stack);
		exit(1);
	}
}

int		main(int argc, char **argv)
{
	t_stack	*stack;
	int		opts;

	(argc-- ==  1) ? exit(0): argv++;
	stack = (t_stack *)malloc(sizeof(t_stack));
	opts = parse_opts(&argc, &argv, stack);
	if (argc == 1)
		split_args(argc, argv, stack);
	initialize_stack(stack, argc);
	stack = parse_args(argc, argv, stack);
	stack->prnt_instrc = 0;
	if (!(is_sorted(stack->a_stack, stack->a_size)))
			ft_putstr("OK\n");
	else
			ft_putstr("KO\n");
	free_stack(stack);
	return (0);
}
