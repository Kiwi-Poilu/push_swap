/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobouatt <sobouatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:15:27 by sobouatt          #+#    #+#             */
/*   Updated: 2021/11/25 20:23:53 by sobouatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** PA : a, b, stack_size
** PB : b, a, stack_size
*/

void	move_push(int *a, int *b, int stack_size)
{
	int	i;
	int	tmp;

	i = 0;
	if (check_empty_stack(b, stack_size))
		return ;
	tmp = b[0];
	while (i < stack_size)
	{
		b[i] = b[i + 1];
		if (b[i++] == 0)
			break ;
	}
	if (a[0] == 0)
	{
		a[0] = tmp;
		return ;
	}
	stack_size--;
	while (stack_size >= 1)
	{
		a[stack_size] = a[stack_size - 1];
		stack_size--;
	}
	a[0] = tmp;
}

void	move_rotate(int *stack, int stack_size)
{
	int	tmp;
	int	i;

	tmp = stack[0];
	i = 1;
	while (i < stack_size)
	{
		if (stack[i] == 0)
		{
			stack[i - 1] = tmp;
			return ;
		}
		else
		{
			stack[i - 1] = stack[i];
		}
		i++;
	}
	stack[i - 1] = tmp;
}

void	move_reverse_rotate(int *stack, int stack_size)
{
	int	i;
	int	tmp;

	i = 0;
	while (stack[i + 1] != 0 && i < stack_size)
		i++;
	if (i != 0)
		tmp = stack[i];
	while (i >= 1)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[i] = tmp;
}

void	move_swap(int *stack)
{
	int	tmp;

	if (stack[0] != 0 && stack[1] != 0)
	{
		tmp = stack[0];
		stack[0] = stack[1];
		stack[1] = tmp;
	}
}
