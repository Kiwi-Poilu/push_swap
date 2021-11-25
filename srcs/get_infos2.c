/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 23:30:48 by sobouatt          #+#    #+#             */
/*   Updated: 2021/11/25 23:30:49 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_lowest(const int *stack)
{
	int	i;
	int	lowest;

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

int	get_lowest_sup(const int *a, int b)
{
	int	i;
	int	actual_lowest_sup;
	int	bool;

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

int	find_target(int *a, int b)
{
	int	i;
	int	tmp;

	i = 0;
	if (a[get_lowest(a)] > b || a[get_highest(a)] < b)
		tmp = get_lowest(a);
	else
		tmp = get_lowest_sup(a, b);
	return (tmp);
}

int	get_stack_size(const int *stack)
{
	int	i;

	i = 0;
	while (stack[i] != 0)
		i++;
	return (i);
}
int	get_highest2(const int *stack, int stack_size)
{
	int	i;
	int	highest;

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