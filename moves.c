/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:17:30 by emiro-co          #+#    #+#             */
/*   Updated: 2023/08/01 12:22:04 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, int i)
{
	int	aux;

	if (!a || !a->next)
		return ;
	aux = a->num;
	a->num = a->next->num;
	a->next->num = aux;
	if (i)
		ft_printf("sa\n");
}

void	sb(t_stack *b, int i)
{
	int	aux;

	if (!b || !b->next)
		return ;
	aux = b->num;
	b->num = b->next->num;
	b->next->num = aux;
	if (i)
		ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, 0);
	sb(b, 0);
	ft_printf("ss\n");
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*first;

	first = *b;
	*b = (*b)->next;
	if (*a == NULL)
	{
		*a = first;
		(*a)->next = NULL;
	}
	else
	{
		first->next = *a;
		*a = first;
	}
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*first;

	first = *a;
	*a = (*a)->next;
	if (*b == NULL)
	{
		*b = first;
		(*b)->next = NULL;
	}
	else
	{
		first->next = *b;
		*b = first;
	}
	ft_printf("pb\n");
}
