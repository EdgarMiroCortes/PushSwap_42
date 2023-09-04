/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:00:35 by emiro-co          #+#    #+#             */
/*   Updated: 2023/08/08 16:51:54 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*parse1(char *arg)
{
	char	**s;
	t_stack	*st;
	int		i;
	char	**r;

	i = 0;
	s = ft_split(arg, ' ');
	r = s;
	while (s[i])
	{
		st = parse(st, s[i]);
		i++;
	}
	free_split(s, i);
	return (st);
}

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
		{
			flag = 2;
		}
		else
		{
			return (0);
		}
		i++;
	}
	return (1);
}

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
	if (argc == 2)
		a = parse1(argv[1]);
	else
		while (++i < argc)
			a = parse(a, argv[i]);
	if (checkrepeated(a) == 1 || ft_strlen(argv[1]) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	sort(&a, &b);
	if (a)
		ft_free(a);
	if (b)
		ft_free(b);
	return (0);
}
