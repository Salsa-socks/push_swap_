/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 09:50:20 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/19 08:49:14 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct	s_stack
{
	int			*a_stack;
	int			*b_stack;
	int			a_size;
	int			b_size;
	int			result;
	int			show_stack;
	int			res_instrc;
	int			prnt_instrc;
}				t_stack;

typedef struct	s_moves
{
	int			a_moves;
	int			b_moves;
	int			c_moves;
	char		*art;
	char		*brt;
	char		*c_rot;
	int			elem;
	int			result;
}				t_moves;

void			do_ra(t_stack *stack);
void			do_rb(t_stack *stack);
void			do_rr(t_stack *stack);
void			do_rra(t_stack *stack);
void			do_rrb(t_stack *stack);
void			do_rrr(t_stack *stack);
void			do_sa(t_stack *stack);
void			do_sb(t_stack *stack);
void			do_ss(t_stack *stack);
void			do_pa(t_stack *stack);
void			do_pb(t_stack *stack);
void			do_instrc(t_stack *stack);
int				min_elem(int *stack, int slen);
int				max_elem(int *stack, int slen);
void			first_a(t_stack *stack);
void			sort(t_stack *stack);
int				art(int len, int pos, char **atype);
int				brt(int len, int pos, char **btype);
int				sorted(int *stack, int len);
int				rev_sorted(int *stack, int len);
void			free_stack(t_stack *stack);
void			free_moves(t_moves *moves);
void			del_stacks(t_stack **stacks);
void			check_av(t_stack *stacks, char **av, int ac);
void			print_stacks(t_stack *stacks);
int				find_in_a(int *stack, int len, int el, char **rot_type);
void			global_sort(t_stack *stack);
void			initialize_stack(t_stack *stack, int argc);
int				parse_opts(int *argc, char ***argv, t_stack *stack);
t_stack			*parse_args(int argc, char **argv, t_stack *stack);
int				rev_sorted(int *stack, int len);
int				is_sorted(int *stack, int len);
t_moves			*bst_a_to_b(t_stack *stack);

#endif
