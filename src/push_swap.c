/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 10:08:43 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/07 10:18:21 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char **argv)
{
	t_stack	*stack;
	int		opts;

	(argc-- == 1) ? exit(0) : argv++;
	stack = (t_stack *)malloc(sizeof(t_stack));
	opts = parse_opts(&argv, &argv, stack);
	if (argc == 1)
	{
		argv = ft_strsplit(argv[0], ' ');
		argv = 0;
		while (argv && argv[argc])
			argc++;
		if (argc == 0)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
	}
	initialize_stack(stack, argc);
	stack = parse_args(argc, argv, stack);
	sort(stack);
	free(stack);
	return (0);
}
