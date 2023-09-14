/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:00:35 by emiro-co          #+#    #+#             */
/*   Updated: 2023/09/14 12:28:59 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack *s)
{
	t_stack	*act;
	t_stack	*next;

	act = s;
	while (act != NULL)
	{
		next = act->next;
		free(act);
		act = next;
	}
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int			i;

	i = 0;
	a = NULL;
	if (argc > 1)
		while (++i < argc)
			a = parse(a, argv[i]);
	if ((check_rep(a) == 1 || ft_strlen(argv[1]) == 0) && ft_printf("Error\n"))
		exit(0);
	sort(&a, &b);
	if (a)
		ft_free(a);
	if (b)
		ft_free(b);
	return (0);
}
