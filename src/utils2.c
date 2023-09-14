/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:10:57 by emiro-co          #+#    #+#             */
/*   Updated: 2023/09/14 13:39:14 by emiro-co         ###   ########.fr       */
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
