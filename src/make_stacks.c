/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 06:11:02 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/16 13:50:40 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	validate_int(char **split, char *nbr, int bgn)
{
	int i;

	i = 0;
	if (nbr[i] == '-' || nbr[i] == '+')
	{
		if (!ft_isdigit(nbr[i + 1]))
			return (0);
		i++;
	}
	while (nbr && nbr[i] != '\0')
	{
		if (!ft_isdigit(nbr[i]))
			return (0);
		i++;
	}
	if (ft_atoll(nbr) > INT_MAX || ft_atoll(nbr) < INT_MIN)
		return (0);
	while (split[bgn] && split && nbr)
	{
		if (ft_strequ(split[bgn], nbr))
			return (0);
		bgn++;
	}
	return (1);
}

static void	del_split(char ***split)
{
	int	i;

	i = 0;
	if (*split)
	{
		while ((*split)[i])
			free((*split)[i++]);
		free(*split);
		*split = NULL;
	}
}

static int	split_count(char **split)
{
	int	count;

	count = 0;
	while (*(split++))
		count++;
	return (count);
}

static int	make_stacks(t_stack *stacks, char **split, int count)
{
	int i;

	i = -1;
	stacks->a_stack = (int*)malloc(sizeof(int) * count);
	stacks->b_stack = (int*)ft_memalloc(sizeof(int) * count);
	stacks->a_size = count;
	stacks->b_size = 0;
	while (++i < count)
	{
		if (validate_int(split, split[i], i + 1))
			stacks->a_stack[i] = ft_atoi(split[i]);
		else
		{
			del_stacks(&stacks);
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
	}
	return (1);
}

void		check_av(t_stack *stacks, char **av, int ac)
{
	char		**split;

	split = NULL;
	if (ac == 2)
	{
		split = ft_strsplit(av[1], ' ');
		if (!make_stacks(stacks, split, split_count(split)))
		{
			del_split(&split);
			exit(1);
		}
		del_split(&split);
	}
	else if (!make_stacks(stacks, (av + 1), ac - 1))
		exit(1);
	return ;
}
