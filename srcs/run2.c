/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 23:05:48 by sobouatt          #+#    #+#             */
/*   Updated: 2021/11/25 23:05:49 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	run_rrb(int *b, int stack_size)
{
	move_reverse_rotate(b, stack_size);
	ft_putstr("rrb\n");
}

void	run_sa(int *a)
{
	move_swap(a);
	ft_putstr("sa\n");
}

void	run_sb(int *b)
{
	move_swap(b);
	ft_putstr("sb\n");
}
