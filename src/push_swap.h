/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 09:50:20 by bnkosi            #+#    #+#             */
/*   Updated: 2019/08/11 11:28:07 by bnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "/libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

typdef struct 	t_stack
{
	int			*a_stack;
	int 		*b_stack;
	int 		a_size;
	int			b_size;
	int 		result;
	int			show_stack;
	int			res_instrc;
	int			prnt_instrc;
}				t_stack;

typedef struct 	m_moves
{
	int			a_moves;
	int			b_moves;
	int			c_moves;
	char		*art;
	char		*brt;
	char		*c_rot;
	int			elem;
	int			result;
}				m_moves;

void			do_ra(t_stack *stack);
void			do_rb(t_stack *stack);
void			do_rr(t_stack *stack);
void			do_rra(t_stack *stack);
void			dr_rrb(t_stack *stack);
void			do_rrr(t_stack *stack);
void			do_sa(t_stack *stack);
void			do_sb(t_stack *stack);
void			do_ss(t_stack *stack);
void			do_pa(t_stack *stack);
void			do_pb(t_stack *stack);
int				min_elem(int *stack, int slen);
int				max_elem(int *stack, int slen);
void			first_a(t_stack *stack);
static void		sort_c(t_stack *stack);
void			sort(t_stack, *stack);
int				art(int len, int pos, char **atype);
int				brt(int len, int pos, char **btype);
int				sorted(int *stack, int len);
int				rev_sorted(int *stack, int len);
void			free_stack(t_stack *stack);
void			free_moves(m_moves *moves);
static int		get_instruction(t_stack *stack, char *instr);
static void		do_instrc(t_stack *stack);
static void		split_args(int argc, char **argv, t_stack stack);
int				find_in_a(int *stack, int len, int el, char **rot_type);
void			insert_in_a(t_stack *stack);
static void		insert_in_b(t_stack *stack);
void			global_sort(t_stack *stack);
static int		validate_args(char **argv, char *arg, int start);
void			initialize_stack(t_stack *stack, int argc);
int				parse_opts(int *argc, char ***argv, t_stack *stack);
t_stack			parse_args(int argc, char **argv, t_stack stack);
int				rev_sorted(int *stack, int len);
void			sort(t_staack *stack);
static void		sort_c(t_stack *stack);
int				sorted(int *stack, int len);
static int		find_in_b(int *stack, int l, int el, char **rot_type);
int				find_com(m_moves *moves);
static m_moves	*calc_a_to_b(t_stack *stack, int pos);
m_moves			bst_a_to_b(t_stack stack);

#endif
