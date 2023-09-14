/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:17:30 by emiro-co          #+#    #+#             */
/*   Updated: 2023/08/01 12:22:36 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, int i)
{
	t_stack	*last;
	t_stack	*pen;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	pen = NULL;
	last = *a;
	while (last->next != NULL)
	{
		pen = last;
		last = last->next;
	}
	pen->next = NULL;
	last->next = *a;
	*a = last;
	if (i)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, int i)
{
	t_stack	*last;
	t_stack	*pen;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	pen = NULL;
	last = *b;
	while (last->next != NULL)
	{
		pen = last;
		last = last->next;
	}
	pen->next = NULL;
	last->next = *b;
	*b = last;
	if (i)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	ft_printf("rrr\n");
}
