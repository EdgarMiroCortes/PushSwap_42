/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:12:31 by emiro-co          #+#    #+#             */
/*   Updated: 2023/09/04 12:08:23 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

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

//   ~~~   PRINCIPAL   ~~~   //
int		*first(int argc, char *argv[]);
t_stack	*parse(t_stack *s, char *arg);
t_stack	*parse1(char *arg);

//   ~~~   ORDENAR   ~~~   //
void	sort(t_stack **a, t_stack **b);
void	order2(t_stack *a);
void	ob2(t_stack *a);
void	order3(t_stack **a);
void	ob3(t_stack **a);
void	order4(t_stack **a, t_stack**b);
void	order5(t_stack **a, t_stack**b);
void	order(t_stack **a, t_stack **b);
void	search2aux1(t_moves bigger, t_stack **b, t_stack **a);
void	search2aux2(t_moves big, t_stack **b, int *nums, int last);

//   ~~~   UTILS   ~~~   //
int		slen(t_stack *stack);
size_t	ft_strlen(const char *str);
int		isnum(char *num);
int		peq(t_stack **a);
int		*min(t_stack **a, int x);
int		**ft_set(t_stack **a, int sizea, int sizeb, int sizec);
void	ft_sep(t_stack **a, t_stack **b);
void	ft_sep2(t_stack **a, t_stack **b, int size, int *first);
void	last10(t_stack **a, t_stack **b, int sizeb);
void	search2big(t_stack **a, t_stack **b);
t_moves	ft_locate(int num, t_stack *b, int len);
int		checksort(t_stack *stack);
int		checkrepeated(t_stack *stack);
int		*min2(int tamano, int *numeros);
int		check(char *arg);
char	**free_split(char **s, size_t j);

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

#endif