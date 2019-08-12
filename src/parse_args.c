/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:08:11 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/12 13:25:23 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		validate_args(char **argv, char *arg, int start)
{
	int i;

	i = 0;
	while (*arg && arg[i] != '\0')
	{
		if (!ft_isdigit(arg[i]) && arg[i] != '-')
			return (0);
		i++;
	}
	if (ft_atoll(arg) > INT_MAX || ft_atoll(arg) < INT_MIN)
		return (0);
	while (argv[start] && argv && arg)
	{
		if (ft_strequ(argv[start], arg))
			return (0);
		start++;
	}
	return (1);
}

void			initialize_stack(t_stack *stack, int argc)
{
	stack->a_stack = (int *)malloc(sizeof(int) * argc);
	stack->b_stack = (int *)malloc(sizeof(int) * argc);
	stack->a_size = argc;
	stack->b_size = 0;
	stack->res_instrc = 0;
	stack->prnt_instrc = 1;
}

int				parse_opts(int *argc, char ***argv, t_stack *stack)
{
	int			i;

	i = 0;
	stack->result = 0;
	stack->show_stack = 0;
	stack->show_stack = 0;
	while (i < *argc && *((*argv)[i]) == '-')
	{
		if (ft_strequ((*argv)[i], "-v"))
			stack->show_stack = 1;
		else if (ft_strequ((*argv)[i], "-t"))
			stack->result = 1;
		else
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
	*argc -= i;
	*argv += i;
	return (i);
}

t_stack			*parse_args(int argc, char **argv, t_stack *stack)
{
	int			i;

	i = 0;
	while (i < argc)
	{
		if (validate_args(argv, argv[i], i + 1))
			stack->a_stack[i] = ft_atoll(argv[i]);
		else
		{
			free_stack(stack);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
	return (stack);
}
