/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 23:03:08 by sobouatt          #+#    #+#             */
/*   Updated: 2021/11/25 23:03:09 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	run_pa(int *a, int *b, int stack_size)
{
	move_push(a, b, stack_size);
	ft_putstr("pa\n");
}

void	run_pb(int *a, int *b, int stack_size)
{
	move_push(b, a, stack_size);
	ft_putstr("pb\n");
}

void	run_ra(int *a, int stack_size)
{
	move_rotate(a, stack_size);
	ft_putstr("ra\n");
}

void	run_rb(int *b, int stack_size)
{
	move_rotate(b, stack_size);
	ft_putstr("rb\n");
}

void	run_rra(int *a, int stack_size)
{
	move_reverse_rotate(a, stack_size);
	ft_putstr("rra\n");
}
