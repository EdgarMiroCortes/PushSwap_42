/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:10:43 by emiro-co          #+#    #+#             */
/*   Updated: 2023/09/18 12:37:03 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	search2big(t_stack **a, t_stack **b)
{
	int		*nums;
	int		last;
	t_moves	bigger;
	t_moves	big;

	nums = min(b, 1);
	last = slen(*b) - 1;
	bigger = ft_locate(nums[last], *b, slen(*b));
	big = ft_locate(nums[last - 1], *b, slen(*b));
	if (bigger.min < big.min)
	{
		if (bigger.rb > bigger.rrb)
		{
			while ((*b)->num != bigger.num)
				rrb(b, 1);
		}
		else
		{
			while ((*b)->num != bigger.num)
				rb(b, 1);
		}
		pa(a, b);
		big = ft_locate(nums[last - 1], *b, slen(*b));
		if (big.rb > big.rrb)
		{
			while ((*b)->num != big.num)
				rrb(b, 1);
		}
		else
		{
			while ((*b)->num != big.num)
				rb(b, 1);
		}
		pa(a, b);
	}
	else
	{
		if (big.rb > big.rrb)
		{
			while ((*b)->num != big.num)
				rrb(b, 1);
		}
		else
		{
			while ((*b)->num != big.num)
				rb(b, 1);
		}
		pa(a, b);
		bigger = ft_locate(nums[last], *b, slen(*b));
		if (bigger.rb > bigger.rrb)
		{
			while ((*b)->num != bigger.num)
				rrb(b, 1);
		}
		else
		{
			while ((*b)->num != bigger.num)
				rb(b, 1);
		}
		pa(a, b);
	}
	free(nums);
	order2(*a);
}
