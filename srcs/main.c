/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:43:54 by sobouatt          #+#    #+#             */
/*   Updated: 2021/11/25 22:05:48 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"



int	fill_tmp(int ac, char **av, int *tmp)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		tmp[i - 1] = ft_strtol(av[i]);
		if ((tmp[i - 1] == INT_MAX || tmp[i - 1] == INT_MIN) && errno == ERANGE)
			return (1);
		i++;
	}
	return (0);
}



void	rotate_for_target(int *a, int target)
{
	int	i;

	i = 0;
	if ((get_stack_size(a) - target) < target)
	{
		while (i < (get_stack_size(a) - target))
		{
			run_rra(a, get_stack_size(a));
			i++;
		}
	}
	else
	{
		while (i < target)
		{
			run_ra(a, get_stack_size(a));
			i++;
		}
	}
}

int	ft_error(int ac, char **av, int *tmp)
{
	int	ret;

	ret = 0;
	if (tmp == NULL)
		return (1);
	if (ac < 2)
		ret = 1;
	if (check_nb(av + 1))
		ret = 1;
	if (fill_tmp(ac, av, tmp))
		ret = 1;
	if (fill_tmp(ac, av, tmp))
		ret = 1;
	if (check_dup(tmp, ac - 1))
		return (1);
	if (ret == 1)
	{
		free(tmp);
		return (1);
	}
	return (0);
}

void	push_swap(t_stack *stack, int ac)
{
	if (ac == 4)
		three(stack->a);
	else if (ac <= 6 && ac != 3)
		five(stack->a, stack->b);
	else
		sort_a(stack, 1, get_highest2(stack->a, ac - 1), ac);
}

int	main(int ac, char **av)
{
	int		*tmp;
	t_stack	stack;

	tmp = malloc((ac) * sizeof(int));
	if (ft_error(ac, av, tmp))
		return (ft_putstr("Error\n"));
	stack.a = malloc ((ac) * sizeof(int));
	if (stack.a == NULL)
		return (0);
	stack.a[ac - 1] = 0;
	stack.b = malloc ((ac) * sizeof(int));
	if (stack.b == NULL)
	{
		free(stack.a);
		return (0);
	}
	fill_stack(ac, tmp, stack.a);
	free(tmp);
	stack.a[ac - 1] = 0;
	ft_memset(stack.b, 0, (ac) * sizeof (int));
	push_swap(&stack, ac);
	free(stack.a);
	free(stack.b);
}
