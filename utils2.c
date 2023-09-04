/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:10:57 by emiro-co          #+#    #+#             */
/*   Updated: 2023/08/08 16:53:38 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	peq(t_stack **a)
{
	t_stack	*current;
	int		min;

	current = *a;
	min = current->num;
	while (current != NULL)
	{
		if (current->num < min)
			min = current->num;
		current = current->next;
	}
	return (min);
}

int	*min(t_stack **a, int x)
{
	t_stack	*current;
	int		*numeros;
	int		tamano;
	int		i;

	tamano = slen(*a);
	numeros = (int *)malloc(tamano * sizeof(int));
	current = *a;
	i = x;
	i = 0;
	while (current != NULL)
	{
		numeros[i] = current->num;
		current = current->next;
		i++;
	}
	return (min2(tamano, numeros));
}

int	*min2(int tamano, int *numeros)
{
	int	sorted;
	int	j;
	int	i;
	int	temp;

	j = 0;
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < tamano - j - 1)
		{
			if (numeros[i] > numeros[i + 1])
			{
				temp = numeros[i];
				numeros[i] = numeros[i + 1];
				numeros[i + 1] = temp;
				sorted = 0;
			}
			i++;
		}
		j++;
	}
	return (numeros);
}

int	checkrepeated(t_stack *stack)
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

char	**free_split(char **s, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
		free(s[i++]);
	free(s);
	return (0);
}
