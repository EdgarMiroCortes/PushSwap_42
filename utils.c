/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:10:57 by emiro-co          #+#    #+#             */
/*   Updated: 2023/08/03 11:49:36 by emiro-co         ###   ########.fr       */
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

int	checksort(t_stack *stack)
{
	if (stack == NULL || stack->next == NULL)
		return (1);
	if (stack->num > stack->next->num)
		return (0);
	return (checksort(stack->next));
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	isnum(char *num)
{
	int	i;

	i = 0;
	while (num[i] != '\0')
	{
		if ((num[i] >= '\060' && num[i] <= '\071') || (num[i] == 45))
			i++;
		else
			return (-1);
	}
	return (1);
}
