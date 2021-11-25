/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 23:18:30 by sobouatt          #+#    #+#             */
/*   Updated: 2021/11/25 23:18:32 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	three(int *a)
{
	if (is_sorted(a, 3))
		return ;
	if (a[0] > a[1] && a[1] < a[2] && a[2] > a[0])
		run_sa(a);
	else if (a[0] > a[1] && a[1] > a[2] && a[2] < a[0])
	{
		run_sa(a);
		run_rra(a, 3);
	}
	else if (a[0] > a[1] && a[1] < a[2] && a[2] < a[0])
		run_ra(a, 3);
	else if (a[0] < a[1] && a[1] > a[2] && a[2] > a[0])
	{
		run_sa(a);
		run_ra(a, 3);
	}
	else if (a[0] < a[1] && a[1] > a[2] && a[2] < a[0])
		run_rra(a, 3);
}


void	five(int *a, int *b)
{
	int	i;
	int	target;

	if (is_sorted(a, 5))
		return ;
	run_pb(a, b, get_stack_size(a));
	run_pb(a, b, get_stack_size(a));
	three(a);
	i = 0;
	while (i < 2)
	{
		target = find_target(a, b[0]);
		rotate_for_target(a, target);
		run_pa(a, b, 5);
		i++;
	}
	while (is_sorted(a, get_stack_size(a)) == 0)
		run_ra(a, get_stack_size(a));
}

void	sort_a(t_stack *stack, int low, int high, int stack_size)
{
	int	mid;
	int	r_count;

	r_count = 0;
	if (low >= high)
		return ;
	mid = (low + high) / 2;
	while (contain_lower(stack->a, mid, stack_size))
	{
		if (is_sorted(stack->a, stack_size) == 1)
			return ;
		if (stack->a[0] > mid)
		{
			run_ra(stack->a, stack_size);
			r_count++;
		}
		else
			run_pb(stack->a, stack->b, stack_size);
	}
	if ((get_stack_size(stack->a) - r_count) < r_count)
		compensate_ra(stack->a, stack_size, r_count);
	else
		compensate_rra(stack->a, stack_size, r_count);
	sort_a(stack, mid + 1, high, stack_size);
	sort_b(stack, low, mid, stack_size);
}

void	sort_b(t_stack *stack, int low, int high, int stack_size)
{
	int	r_count;

	r_count = 0;
	if (low > high)
		return ;
	while (contain_greater_equal(stack->b, (low + high) / 2, stack_size))
	{
		if (is_sorted(stack->a, stack_size) == 1)
			return ;
		if (stack->b[0] < (low + high) / 2)
		{
			run_rb(stack->b, stack_size);
			r_count++;
		}
		else
			run_pa(stack->a, stack->b, stack_size);
	}
	if ((get_stack_size(stack->b) - r_count) < r_count)
		compensate_rb(stack->b, stack_size, r_count);
	else
		compensate_rrb(stack->b, stack_size, r_count);
	sort_a(stack, (low + high) / 2, high, stack_size);
	sort_b(stack, low, ((low + high) / 2) - 1, stack_size);
}

void	fill_stack(int ac, const int *t, int *a)
{
	int	i;
	int	j;
	int	pv;
	int	cr;

	i = 0;
	while (i < ac - 1)
	{
		cr = 0;
		j = 0;
		while (j < ac - 1)
		{
			if (i != 0)
			{
				if ((t[j] < t[cr] && t[j] > t[pv]) || t[cr] <= t[pv])
					cr = j;
			}
			else if (t[j] < t[cr])
				cr = j;
			j++;
		}
		a[cr] = i + 1;
		pv = cr;
		i++;
	}
}
