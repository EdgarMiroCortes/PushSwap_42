/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:10:43 by emiro-co          #+#    #+#             */
/*   Updated: 2023/09/14 14:19:14 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ob2(t_stack *a)
{
	if (a->num < a->next->num)
		sb(a, 1);
}

void	order2(t_stack *a)
{
	if (a->num > a->next->num)
		sa(a, 1);
}

void	order3(t_stack **a)
{
	if (((*a)->num < (*a)->next->num)
		&& ((*a)->next->num < (*a)->next->next->num))
		return ;
	while (((*a)->next->num > (*a)->next->next->num)
		|| ((*a)->num > (*a)->next->next->num))
		ra(a, 1);
	if ((*a)->num > (*a)->next->num)
		sa(*a, 1);
}

void	order4(t_stack **a, t_stack **b)
{
	int	min;

	min = peq(a);
	while ((*a)->num != min)
		ra(a, 1);
	pb(a, b);
	order3(a);
	pa(a, b);
}
