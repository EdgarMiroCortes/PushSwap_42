/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:17:30 by emiro-co          #+#    #+#             */
/*   Updated: 2023/08/01 12:22:25 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, int i)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*current;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	second = (*a)->next;
	current = second;
	while (current->next != NULL)
		current = current->next;
	current->next = first;
	first->next = NULL;
	*a = second;
	if (i)
		ft_printf("ra\n");
}

void	rb(t_stack **b, int i)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*current;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	first = *b;
	second = (*b)->next;
	current = second;
	while (current->next != NULL)
		current = current->next;
	current->next = first;
	first->next = NULL;
	*b = second;
	if (i)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	ft_printf("rr\n");
}
