/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:10:57 by emiro-co          #+#    #+#             */
/*   Updated: 2023/09/14 14:21:59 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_moves	ft_locate(int num, t_stack *b, int len)
{
	int		i;
	int		ok;
	t_moves	move;

	i = 0;
	move.num = num;
	while (b)
	{
		if (b->num == num)
		{
			ok = i;
			move.rb = i;
		}
		b = b->next;
		i++;
	}
	move.rrb = len - ok;
	if (move.rrb > move.rb)
		move.min = move.rb;
	else
		move.min = move.rrb;
	return (move);
}

int	slen(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
