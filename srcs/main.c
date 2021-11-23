/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:43:54 by sobouatt          #+#    #+#             */
/*   Updated: 2021/11/22 23:53:51 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../include/push_swap.h"


int get_highest2(const int *stack, int stack_size)
{
	int i;
	int highest;

	i = 0;
	highest = 0;
	while (i < stack_size)
	{
		if (stack[i] > highest)
			highest = i;
		i++;
	}
	return (i);
}

void	sort_a(int *a, int *b, int low, int high, int stack_size)
{
	int	mid;
	int	r_count;

	r_count = 0;
	if (is_sorted(a, stack_size) == 1)
		return ;
	if (low >= high)
		return ;
	mid = (low + high) / 2;
	while (contain_lower(a, mid, stack_size))
	{
		if (is_sorted(a, stack_size) == 1)
			return ;
		if (a[0] > mid)
		{
			move_rotate(a, stack_size);
			printf("ra\n");
			r_count++;
		}
		else
		{
			move_PUSH(b, a, stack_size);
			printf("pb\n");
		}
	}
	if ((get_stack_size(a) - r_count) < r_count)
	{
		while (r_count < get_stack_size(a))
		{
			printf("ra\n");
			move_rotate(a, stack_size);
			r_count++;
		}
	}
	else
	{
		while (r_count > 0)
		{
			printf("rra\n");
			move_reverse_rotate(a, stack_size);
			r_count--;
		}
	}
	sort_a(a, b, mid + 1, high, stack_size);
	sort_b(a, b, low, mid, stack_size);
}

void	sort_b(int *a, int *b, int low, int high, int stack_size)
{
	int	mid;
	int	r_count;

	r_count = 0;
	if (is_sorted(a, stack_size) == 1)
		return ;
	if (low > high)
		return ;
	mid = (low + high) / 2;
	while (contain_greater_equal(b, mid, stack_size))
	{
		if (is_sorted(a, stack_size) == 1)
			return ;
		if (b[0] < mid)
		{
			printf("rb\n");
			move_rotate(b, stack_size);
			r_count++;
		}
		else
		{
			move_PUSH(a, b, stack_size);
			printf("pa\n");
		}
	}
	//highest - rcount vs r_count
	//x rb ou y rrb
	//x = get_stack_size - rcount;
	//y = r_count;
	if ((get_stack_size(b) - r_count) < r_count)
	{
		while (r_count < get_stack_size(b))
		{
			printf("rb\n");
			move_rotate(b, stack_size);
			r_count++;
		}
	}
	else
	{
		while (r_count > 0)
		{
			printf("rrb\n");
			move_reverse_rotate(b, stack_size);
			r_count--;
		}
	}
	sort_a(a, b, mid, high, stack_size);
	sort_b(a, b, low, mid - 1, stack_size);
}

int	fill_tmp(int ac, char **av, int *tmp)
{
	int i;

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

void fill_stack(int ac, const int *tmp, int *a)
{
	int i;
	int j;
	int previous;
	int current;
	int bool;

	i = 0;
	bool = 0;
	while (i < ac - 1)
	{
		current = 0;
		j = 0;
		while (j < ac - 1)
		{
			if (bool == 1)
			{
				if ((tmp[j] < tmp[current] && tmp[j] > tmp[previous]) || tmp[current] <= tmp[previous])
				{
					current = j;
				}
			}
			else
			{
				if (tmp[j] < tmp[current])
					current = j;
			}
			j++;
		}
		a[current] = i + 1;
		previous = current;
		bool = 1;
		i++;
	}
}

int check_limits(char **av)
{
	int i;
	int ret;

	i = 0;
	while (av[i])
	{
		ret = ft_strtol(av[i]);
		if ((ret == INT_MAX || ret == INT_MIN) && errno == ERANGE)
			return (1);
		i++;
	}
	return (0);
}

void	three(int *a)
{
	display_stack(a, get_stack_size(a));
	printf("%d\n", a[0]);
	printf("%d\n", a[1]);
	printf("%d\n", a[2]);
	if (is_sorted(a, 3))
		return ;
	if (a[0] > a[1] && a[1] < a[2] && a[2] < a[0])
	{
		printf("sa\n");
		move_swap(a);
	}
	else if (a[0] > a[1] && a[1] > a[2] && a[2] < a[0])
	{
		printf("sa\n");
		move_swap(a);
		printf("rra\n");
		move_reverse_rotate(a, 3);
	}
	else if (a[0] > a[1] && a[1] < a[2] && a[2] > a[0])
	{
		printf("ra\n");
		move_rotate(a, 3);
	}
	else if (a[0] > a[1] && a[1] > a[2] && a[2] > a[0])
	{
		printf("sa\n");
		move_swap(a);
		printf("ra\n");
		move_rotate(a, 3);
	}
	else if (a[0] < a[1] && a[1] > a[2] && a[2] < a[0])
	{
		printf("rra\n");
		move_reverse_rotate(a, 3);
	}
	display_stack(a, get_stack_size(a));
}

int 	get_lowest(int *stack)
{
	int i;
	int lowest;

	i = 0;
	lowest = 0;
	while (stack[i] != 0)
	{
		if (stack[i] < stack[lowest])
			lowest = i;
		i++;
	}
	return (lowest);
}

int 	get_lowest_sup(const int *a, int b)
{
	int i;
	int actual_lowest_sup;
	int bool;

	i = 0;
	bool = 0;
	while (a[i] != 0)
	{
		if (a[i] > b && bool == 0)
		{
			actual_lowest_sup = i;
			bool = 1;
		}
		if (a[i] > b && a[i] < a[actual_lowest_sup])
			actual_lowest_sup = i;
		i++;
	}
	return (actual_lowest_sup);
}

int		find_target(int *a, int b)
{
	int i;
	int tmp;

	i = 0;
	display_stack(a, get_stack_size(a));
	if (a[get_lowest(a)] > b || a[get_highest(a)] < b)
	{
		printf("get_lowest(a) = %d\n", get_lowest(a));
		printf("get_highest(a) = %d\n", get_highest(a));
		printf("get_lowest\n");
		tmp = get_lowest(a);
	}
	else
	{
		printf("get_lowest(a) = %d\n", get_lowest(a));
		printf("get_highest(a) = %d\n", get_highest(a));
		printf("get_lowest_supp\n");
		tmp = get_lowest_sup(a, b);
	}
	printf("b = %d\n", b);
	printf("tmp = %d\n", tmp);
	return (tmp);
}

int	get_stack_size(const int *stack)
{
	int i;

	i = 0;
	while (stack[i] != 0)
		i++;
	return (i);
}

void rotate_for_target(int *a, int target)
{
	int i;

	i = 0;
	while (i < target)
	{
		printf("ra\n");
		move_rotate(a, get_stack_size(a));
		i++;
	}
}

void five(int *a, int *b)
{
	int i;
	int target;

	if (is_sorted(a, 5))
		return ;
	printf("pb\n");
	move_PUSH(b, a, 5);
	printf("pb\n");
	move_PUSH(b, a, 5);
	three(a);
	i = 0;
	while (i < 2)
	{
		target = find_target(a, b[0]);
		printf("target = %d\n", target);
		rotate_for_target(a, target);
		printf("pa\n");
		move_PUSH(a, b, 5);
		i++;
	}
	display_stack(a, get_stack_size(a));
	while (is_sorted(a, get_stack_size(a)) == 0)
	{
		//printf("ra\n");
		move_rotate(a, get_stack_size(a));
	}
}

int	main(int ac, char **av)
{
	int *a;
	int *b;
	int *tmp;

	if (check_nb(av + 1))
		return (ft_putstr("Error\n"));
	if (check_limits(av + 1))
		return (ft_putstr("Error, not an int\n"));
	tmp = malloc((ac)* sizeof(int));
	if (fill_tmp(ac, av, tmp))
	{
		free(tmp);
		return (ft_putstr("Error, not an int\n"));
	}
	if (check_dup(tmp, ac - 1))
	{
		free(tmp);
		return (ft_putstr("Error\n"));
	}
	a = malloc ((ac) * sizeof(int));
	a[ac - 1] = 0;
	b = malloc ((ac)  * sizeof(int));
	fill_stack(ac, tmp, a);
	//printf("highest of A = %d\n", get_highest2(a, ac - 1));
	free(tmp);
	a[ac - 1] = 0;
	memset(b, 0, (ac) * sizeof (int));
	if (ac == 4)
		three(a);
	else if (ac == 6)
		five(a, b);
	else
		sort_a(a, b, 1, get_highest2(a, ac - 1), ac);
	display_stack(a, get_stack_size(a));
	//printf("%d\n", get_stack_size(a));
	//printf("%d\n", get_highest2(a, ac - 1));
	free(a);
	free(b);
}
