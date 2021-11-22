#include "../include/push_swap.h"

int get_highest(const int *stack, int stack_size)
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

int check_empty_stack(const int *stack, int stack_size)
{
	int i;

	i = 0;
	while (i < stack_size)
	{
		if (stack[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

int	contain_greater_equal(const int *stack, int mid, int stack_size)
{
	int i;

	i = 0;
	while (i < stack_size)
	{
		if (stack[i] == 0)
			return (0);
		if (stack[i] >= mid)
			return(1);
		i++;
	}
	return (0);
}


int contain_lower(const int *stack, int mid, int stack_size)
{
	int i;

	i = 0;
	while (i < stack_size)
	{
		if (stack[i] == 0)
			return (0);
		if (stack[i] <= mid)
			return (1);
		i++;
	}
	return (0);
}

int get_stack_size(const int *stack)
{
	int i;

	i = 0;
	while (stack[i])
	{
		if (stack[i] == 0)
			return (i);
		i++;
	}
	return (i);
}

int is_sorted(const int *stack, int stack_size)
{
	stack_size--;
	while (stack_size >= 1)
	{
		if (stack[stack_size] > stack[stack_size - 1])
			stack_size--;
		else
			return (0);
	}
	return (1);
}