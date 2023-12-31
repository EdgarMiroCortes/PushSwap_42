/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:10:43 by emiro-co          #+#    #+#             */
/*   Updated: 2023/09/18 20:05:18 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order5(t_stack **a, t_stack **b)
{
	int	*peq;
	int	i;

	i = 2;
	peq = min(a, 2);
	while (i)
	{
		if (((*a)->num == peq[0]) || ((*a)->num == peq[1]))
		{
			pb(a, b);
			i--;
		}
		else
			ra(a, 1);
	}
	ob2(*b);
	order3(a);
	pa(a, b);
	pa(a, b);
	free(peq);
}

void	order(t_stack **a, t_stack **b)
{
	ft_sep(a, b);
	while (slen(*b) > 0)
	{
		if (slen(*b) == 1)
		{
			pa(a, b);
		}
		else if (slen(*b) == 2)
		{
			pa(a, b);
			pa(a, b);
			order2(*a);
		}
		else
			ft_magic(a, b);
	}
}

int	*ft_set_limiters(int *nums, t_stack **a)
{
	int size;
	int	*first;
	int i;

	first = NULL;
	size = (slen(*a) / 6);
	i = 0;
	first[0] = nums[i];
	while (size--)
		i++;
	first[1] = nums[i];
	size = ((slen(*a) / 6) + (slen(*a) % 6));
	while (size--)
		i++;
	first[2] = nums[i];
	size = (slen(*a) / 6);
	while (size--)
		i++;
	first[3] = nums[i];
	size = (slen(*a) / 6);
	while (size--)
		i++;
	first[4] = nums[i];
	size = (slen(*a) / 6);
	while (size--)
		i++;
	first[5] = nums[i];
	free(nums);
	return (first);
}

void	ft_sep(t_stack **a, t_stack **b)
{
	int	*nums;
	int	size;
	int	*first;
	size = slen(*a);
	nums = min(a, 1);
	first = ft_set_limiters(nums, a);
	
	free(nums);
	ft_sep2(a, b, size, first);
}

void	ft_sep2(t_stack **a, t_stack **b, int size, int *first)
{
	size = slen(*a);
	while (size)
	{
		if ((*a)->num >= first[2] && (*a)->num < first[4])
		{
			pb(a, b);
			if ((*b)->num < first[3])
				rb(b, 1);
		}
		else
			ra(a, 1);
		size --;
	}
	size = slen(*a);
	while (size)
	{
		if ((*a)->num >= first[1] && (*a)->num < first[5])
		{
			pb(a, b);
			if ((*b)->num < first[4])
				rb(b, 1);
		}
		else
			ra(a, 1);
		size --;
	}
	size = slen(*a);
	while (size--)
	{
		pb(a, b);
		if ((*b)->num < first[3])
			rb(b, 1);
	}
}

void	sort(t_stack **a, t_stack **b)
{
	if (slen(*a) == 1 || checksort(*a) == 1)
		return ;
	else if (slen(*a) == 2)
		order2(*a);
	else if (slen(*a) == 3)
		order3(a);
	else if (slen(*a) == 4)
		order4(a, b);
	else if (slen(*a) == 5)
		order5(a, b);
	else
		order(a, b);
}
