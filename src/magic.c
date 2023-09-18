/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:10:43 by emiro-co          #+#    #+#             */
/*   Updated: 2023/09/18 17:48:33 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_magic(t_stack **a, t_stack **b)
{
	t_trio	trio;
	t_duo	duo;

	trio = ft_set_trio(b, min(b, 1), slen(*b) - 1);
	if (trio.first.min <= trio.second.min && trio.first.min <= trio.third.min)
	{
		ft_move(a, b, trio.first);
		duo = ft_set_duo(b, min(b, 1), slen(*b) - 1);
		ft_solve_duo(a, b, duo, 1);
		return ;
	}
	else if ((trio.second.min <= trio.first.min && trio.second.min < trio.third.min))
	{
		ft_move(a, b, trio.second);
		duo = ft_set_duo(b, min(b, 1), slen(*b) - 1);
		ft_solve_duo(a, b, duo, 2);
		return ;
	}
	else if ((trio.third.min <= trio.first.min && trio.third.min <= trio.second.min))
	{
		ft_move(a, b, trio.third);
		duo = ft_set_duo(b, min(b, 1), slen(*b) - 1);
		ft_solve_duo(a, b, duo, 3);
		return ;
	}
}

void	ft_solve_duo(t_stack **a, t_stack **b, t_duo duo, int num_a)
{
	t_moves		last;
	(void) (num_a);
	if (duo.first.min < duo.second.min)
	{
		ft_move(a, b, duo.first);
		last = ft_locate((min(b, 1))[slen(*b) - 1], *b, slen(*b));
		ft_move(a, b, last);
	}
	else if (duo.second.min <= duo.first.min)
	{
		ft_move(a, b, duo.second);
		last = ft_locate((min(b, 1))[slen(*b) - 1], *b, slen(*b));
		ft_move(a, b, last);
	}
	if (num_a == 1)
	{
		order2(*a);
	}
	if (num_a == 2)
	{
		if (last.num != duo.second.num)
		{
			sa(*a, 1);
			pb(a, b);
			sa(*a, 1);
			pa(a, b);
			order2(*a);
		}
		else
		{
			pb(a, b);
			sa(*a, 1);
			pa(a, b);
			order2(*a);
		}
	}
	if (num_a == 3)
	{
		//sa(*a, 1);
		pb(a, b);
		sa(*a, 1);
		pa(a, b);
		sa(*a, 1);
		pb(a, b);
		order2(*a);
		pa(a, b);
		order2(*a);
	}
}

void	ft_move(t_stack **a, t_stack **b, t_moves num)
{
	if (num.rb > num.rrb)
	{
		while ((*b)->num != num.num)
			rrb(b, 1);
	}
	else
	{
		while ((*b)->num != num.num)
			rb(b, 1);
	}
	pa(a, b);
}

t_trio	ft_set_trio(t_stack **b, int *nums, int last)
{
	t_trio		trio;

	trio.first = ft_locate(nums[last], *b, slen(*b));
	trio.second = ft_locate(nums[last - 1], *b, slen(*b));
	trio.third = ft_locate(nums[last - 2], *b, slen(*b));
	free(nums);
	return (trio);
}

t_duo	ft_set_duo(t_stack **b, int *nums, int last)
{
	t_duo		duo;

	duo.first = ft_locate(nums[last], *b, slen(*b));
	duo.second = ft_locate(nums[last - 1], *b, slen(*b));
	free(nums);
	return (duo);
}
