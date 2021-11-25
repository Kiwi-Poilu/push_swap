/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compensate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 22:14:28 by sobouatt          #+#    #+#             */
/*   Updated: 2021/11/25 22:14:53 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	compensate_rb(int *b, int stack_size, int r_count)
{
	while (r_count < get_stack_size(b))
	{
		run_rb(b, stack_size);
		r_count++;
	}
}

void	compensate_rrb(int *b, int stack_size, int r_count)
{
	while (r_count > 0)
	{
		run_rrb(b, stack_size);
		r_count--;
	}
}

void	compensate_ra(int *a, int stack_size, int r_count)
{
	while (r_count < get_stack_size(a))
	{
		run_ra(a, stack_size);
		r_count++;
	}
}

void	compensate_rra(int *a, int stack_size, int r_count)
{
	while (r_count > 0)
	{
		run_rra(a, stack_size);
		r_count--;
	}
}
