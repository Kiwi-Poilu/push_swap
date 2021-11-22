/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:43:54 by sobouatt          #+#    #+#             */
/*   Updated: 2021/11/11 21:43:55 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../include/push_swap.h"

void sort_a(int *a, int *b, int low, int high, int stack_size)
{
	int mid;
	int r_count;


	r_count = 0;
	if (is_sorted(a, stack_size) == 1)
		return ;
	if (low >= high)
		return;
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
	while (r_count < get_stack_size(a))
	{
		printf("ra\n");
        move_rotate(a, stack_size);
		r_count++;
	}
	sort_a(a, b, mid + 1, high, stack_size);
	sort_b(a, b, low, mid, stack_size);
}

void sort_b(int *a, int *b, int low, int high, int stack_size)
{
	int mid;
	int r_count;

	r_count = 0;
	if (is_sorted(a, stack_size) == 1)
		return ;
	if (low > high)
		return;
	mid = (low + high) / 2;
	while (contain_greater_equal(b, mid, stack_size))
	{
		if (is_sorted(a, stack_size) == 1)
			return ;
		if (b[0] < mid)
		{
            printf("rrb\n");
            move_reverse_rotate(b, stack_size);
			r_count++;
		} else
		{
			move_PUSH(a, b, stack_size);
            printf("pa\n");
		}
	}
	while (r_count < get_stack_size(b))
	{
        printf("rrb\n");
        move_reverse_rotate(b, stack_size);
		r_count++;
	}
	sort_a(a, b, mid, high, stack_size);
	sort_b(a, b, low, mid - 1, stack_size);

}

int fill_tmp(int ac, char **av, int *tmp)
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
	a = malloc ((ac) * sizeof(int));	a[ac - 1] = 0;
	b = malloc ((ac)  * sizeof(int));
	fill_stack(ac, tmp, a);
	free(tmp);
	a[ac - 1] = 0;
	memset(b, 0, (ac - 1) * sizeof (int));
    sort_a(a, b, 1, get_highest(a, ac - 1), ac - 1);
    //display_stack(a, ac);
    //display_stack(a, ac);
	//display_stack(b, ac - 1 );
	free(a);
	free(b);
}