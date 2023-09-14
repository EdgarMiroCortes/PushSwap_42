/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:00:35 by emiro-co          #+#    #+#             */
/*   Updated: 2023/09/14 14:21:47 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*parse(t_stack *s, char *arg)
{
	t_stack	*new;
	t_stack	*act;
	int		num;

	if (check(arg) == 1)
		num = ft_atoi(arg);
	else
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	new = malloc(sizeof(t_stack));
	new->num = num;
	new->next = NULL;
	if (s == NULL)
		s = new;
	else
	{
		act = s;
		while (act->next != NULL)
			act = act->next;
		act->next = new;
	}
	return (s);
}

int	check(char *arg)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] == '-')
		{
			if (flag != 0 || arg[i + 1] == '\0')
				return (0);
			else
				flag = 1;
		}
		else if (ft_isdigit((int)arg[i]))
			flag = 2;
		else
			return (0);
		i++;
	}
	return (1);
}

int	check_rep(t_stack *stack)
{
	t_stack	*current;
	t_stack	*runner;

	if (stack == NULL || stack->next == NULL)
	{
		return (0);
	}
	current = stack;
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (current->num == runner->num)
			{
				return (1);
			}
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

int	checksort(t_stack *stack)
{
	if (stack == NULL || stack->next == NULL)
		return (1);
	if (stack->num > stack->next->num)
		return (0);
	return (checksort(stack->next));
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