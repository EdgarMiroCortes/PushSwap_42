/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:12:31 by emiro-co          #+#    #+#             */
/*   Updated: 2023/09/18 17:51:54 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

//   ~~~   LISTAS  ~~~   //
typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

typedef struct s_moves
{
	int				num;
	int				rrb;
	int				rb;
	int				min;
}					t_moves;

typedef struct s_trio
{
	t_moves			first;
	t_moves			second;
	t_moves			third;
}					t_trio;

typedef struct s_duo
{
	t_moves			first;
	t_moves			second;
}					t_duo;

//   ~~~   PRINCIPAL   ~~~   //
int		*first(int argc, char *argv[]);
t_stack	*parse(t_stack *s, char *arg);

//   ~~~   ORDENAR   ~~~   //
void	sort(t_stack **a, t_stack **b);
void	order2(t_stack *a);
void	ob2(t_stack *a);
void	order3(t_stack **a);
void	order4(t_stack **a, t_stack**b);
void	order5(t_stack **a, t_stack**b);
void	order(t_stack **a, t_stack **b);
/*void	search2aux1(t_moves bigger, t_stack **b, t_stack **a);
void	search2aux2(t_moves big, t_stack **b, int *nums, int last);*/

//   ~~~   CHECKING AND PARSING   ~~~   //
int		checksort(t_stack *stack);
int		check_rep(t_stack *stack);
int		check(char *arg);

//   ~~~   UTILS   ~~~   //
int		slen(t_stack *stack);
size_t	ft_strlen(const char *str);
int		isnum(char *num);
int		peq(t_stack **a);
void	ft_sep(t_stack **a, t_stack **b);
void	ft_sep2(t_stack **a, t_stack **b, int size, int *first);
t_moves	ft_locate(int num, t_stack *b, int len);
int		*min(t_stack **a, int x);
int		*min2(int tamano, int *numeros);

//   ~~~   MOVIMENTS   ~~~   //
void	sa(t_stack	*a, int i);
void	sb(t_stack	*b, int i);
void	ss(t_stack	*a, t_stack	*b);
void	pa(t_stack	**a, t_stack **b);
void	pb(t_stack	**a, t_stack **b);
void	ra(t_stack	**a, int i);
void	rb(t_stack	**b, int i);
void	rr(t_stack	**a, t_stack **b);
void	rra(t_stack **a, int i);
void	rrb(t_stack **b, int i);
void	rrr(t_stack **a, t_stack **b);

//   ~~~   MAGIC   ~~~   //
void	ft_magic(t_stack **a, t_stack **b);
void	ft_solve_duo(t_stack **a, t_stack **b, t_duo duo, int num_a);
void	ft_move(t_stack **a, t_stack **b, t_moves num);
t_trio	ft_set_trio(t_stack **b, int *nums, int last);
t_duo	ft_set_duo(t_stack **b, int *nums, int last);

#endif